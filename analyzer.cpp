#include "position.h"
#include "analyzer.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdio.h>

#ifdef MY_MSVC
#include <Windows.h>
#endif

using namespace std;
using namespace PositionSpace;

namespace AnalyzerSpace
{

	int minimax_depth=SETUP_MINIMAX_DEPTH;
	int deep_search_depth=SETUP_MINIMAX_DEPTH;
	int max_generated_nodes=SETUP_GENERATED_NODES;

	int minimax_depth_corr=0;
	bool show_positions_loaded=false;
	int positions_loaded=0;

	Score global_alpha=-INFINITE_SCORE;
	bool global_quit_search=false;

	pthread_mutex_t display_mutex = PTHREAD_MUTEX_INITIALIZER;

	bool quit_deep_search=false;
	bool deep_search_going=false;

	Score CUTOFF=-9000;
	int DEEPNESS=SETUP_DEEPNESS;
	int DEPTH_BONUS=SETUP_DEPTH_BONUS;

	MyHash<PositionTrunk,DeepHashValue,DEEP_HASH_SHIFT,DEEP_POSITION_BUFFER_SIZE> position_hash;
	DeepHashMove move_buffer[DEEP_MOVE_BUFFER_SIZE];

	MyHashPtr move_alloc_ptr;
	
	KickHash <PositionTrunk,EvalMove,MOVE_HASH_SHIFT> move_hashes[NUM_ANALYZERS];
	
	Analyzer analyzers[NUM_ANALYZERS];
	
	MyQueue<SearchJob,QUEUE_LENGTH> position_queue("job");
	MyQueue<SearchResult,QUEUE_LENGTH> result_queue("result");
	
	void init()
	{
	
		move_alloc_ptr=0;
		
		for(int i=0;i<NUM_ANALYZERS;i++)
		{
			analyzers[i].num_analyzer=i;
			analyzers[i].move_hash=&move_hashes[i];
			
			if(i<NUM_THREADS)
			{
				analyzers[i].start_analyzer();
			}
			
		}
		
	}
	
	DeepHashValue* smart_look_up(Position p)
	{
		DeepHashValue* entry=position_hash.look_up((PositionTrunk*)&p,DONT_CREATE);
		if(entry==NULL)
		{
			PosHashKey key=p.calc_key();
			
			DeepHashValue dummy;
			
			dummy.key=key;
			
			ifstream i(dummy.file_name(),ios::binary);
			
			if(i.is_open())
			{
				i.read((char*)&dummy,sizeof(DeepHashValue));
				if(0==memcmp((PositionTrunk*)&p,(PositionTrunk*)dummy.id,sizeof(PositionTrunk)))
				{
					entry=position_hash.look_up((PositionTrunk*)&p,DO_CREATE);
					
					if(entry==NULL)
					{
						i.close();
						return NULL;
					}
					else
					{
						i.read((char*)&move_buffer[move_alloc_ptr],dummy.move_buffer_size());
						i.close();
						
						entry->moves=move_alloc_ptr;
						entry->no_moves=dummy.no_moves;
						entry->key=dummy.key;
						
						move_alloc_ptr+=entry->no_moves;
						
						positions_loaded++;
						if(show_positions_loaded)
						{
							cout << positions_loaded << " positions loaded" << endl;
						}
						
						return entry;
					}
				}
				else
				{
					return NULL;
				}
			}
			else
			{
				return NULL;
			}
		}
		else
		{
			return entry;
		}
	}
	
	void* analyzer_thread_func(void* void_ptr)
	{	
		
		Analyzer* me=(Analyzer*)void_ptr;
		
		pthread_mutex_lock(&display_mutex);
		//cout << "analyzer " << me->num_analyzer << " started" << endl;
		pthread_mutex_unlock(&display_mutex);
		
		while(true)
		{
		
			if(position_queue.pending())
			{
			
				SearchJob sj;
				position_queue.dequeue(&sj);
				
				/*pthread_mutex_lock(&display_mutex);
				
				cout 
				<< "thread " << me->num_analyzer 
				<< " dequeued " 
				<< sj.line
				<< endl;
				
				pthread_mutex_unlock(&display_mutex);*/
				
				if(sj.multi)
				{
					SearchResult result;
					
					result.m=sj.m;
					me->alphabeta_depth=sj.depth;
					me->verbose=false;
					
					me->nodes=0;
					
					if(!global_quit_search)
					{
						result.score=me->search_alphabeta(sj.p,0,global_alpha,INFINITE_SCORE);
					}
					else
					{
						result.score=INFINITE_SCORE;
					}
					
					result.nodes=me->nodes;
					
					result_queue.enqueue(&result);
				}
				else
				{
					me->enqueue_move_values(sj.p);
				}
				
			}
			else
			{
				Sleep(10);
			}
			
		}
		
	}
	
	void Analyzer::start_analyzer()
	{
		if(pthread_create(&analyzer_thread, NULL, analyzer_thread_func, this))
		{
		
			cout << "Error creating thread." << endl;
			exit(1);

		}
	}
	
	pthread_t deep_search_thread;
	
	Position deep_search_position;
	
	bool minimax_smart=false;
	
	void Analyzer::enqueue_move_values(Position p)
	{
	
		SearchResult result;
		
		result.p=p;
	
		int no_moves=0;
		
		p.init_move_generator();
		
		while(p.next_legal_move())
		{
		
			Position dummy=p;
			dummy.make_move(p.try_move);
			
			search_depth=4;
			search_position=dummy;
			
			search_grad_verbose=false;
			Score score=-search_grad_call();
			search_grad_verbose=true;
			
			result.moves[no_moves].m=p.try_move;
			result.moves[no_moves].original_search_score=score;
			result.moves[no_moves].eval=score;
			
			no_moves++;
			
		}
		
		result.no_moves=no_moves;
		
		result_queue.enqueue(&result);

	}
	
	void* deep_search_thread_func(void* void_ptr)
	{
		
		deep_search_going=true;
		
		cout << "initializing position" << endl << endl;
		
		minimax_depth=SETUP_MINIMAX_DEPTH;
		max_generated_nodes=SETUP_GENERATED_NODES;
		
		minimax_smart=true;
		minimax_depth_corr=(minimax_depth-SETUP_INIT_DEPTH);
		positions_loaded=0;
		show_positions_loaded=true;
		analyzers[NODE_SELECT_ANALYZER].minimax_out(deep_search_position);
		//show_positions_loaded=false;
		minimax_depth_corr=0;
		minimax_smart=false;
		
		do
		{
		
			int no_jobs=0;
			
			SearchJob search_jobs[MAX_GENERATED_NODES];
			
			cout << "selecting nodes" << endl;
			
			deep_search_depth=minimax_depth;
			
			for(int i=0;i<max_generated_nodes;i++)
			{
			
				if(analyzers[NODE_SELECT_ANALYZER].select_node(deep_search_position))
				{
				
					Position p=analyzers[NODE_SELECT_ANALYZER].search_position;
					
					bool found=false;
					
					for(int f=0;f<no_jobs;f++)
					{
						if(0==memcmp((PositionTrunk*)&p,(PositionTrunk*)&search_jobs[f].p,sizeof(PositionTrunk)))
						{
							found=true;
							break;
						}
					}
					
					if(!found)
					{
					
						SearchJob search_job;
						
						search_job.p=p;
						search_job.multi=false;
						
						search_job.line[0]=0;
						for(int i=0;i<analyzers[NODE_SELECT_ANALYZER].node_move_list_ptr;i++)
						{
							strcat(search_job.line,(char*)analyzers[NODE_SELECT_ANALYZER].node_move_list[i].algeb());
							strcat(search_job.line," ");
						}
						
						search_jobs[no_jobs]=search_job;
						
						no_jobs++;
					
					}
					
				}
				
			}
			
			cout << "number of selected nodes " << no_jobs << endl;
			
			MyTimer analysis_t;
			
			for(int f=0;f<no_jobs;f++)
			{
				position_queue.enqueue(&search_jobs[f]);
			}
			
			while(position_queue.pending())
			{
		
				Sleep(50);
		
			}
			
			while(no_jobs)
			{
				
				if(result_queue.pending())
				{
				
					SearchResult result;
					result_queue.dequeue(&result);
					
					DeepHashValue* entry=position_hash.look_up((PositionTrunk*)&result.p,DONT_CREATE);
		
					if(entry==NULL)
					{
						if(move_alloc_ptr>=DEEP_MAX_MOVE_BUFFER_PTR)
						{
							cout << "out of memory" << endl;exit(1);
							deep_search_going=false;
							return NULL;
						}
						else
						{
							entry=position_hash.look_up((PositionTrunk*)&result.p,DO_CREATE);
							
							if(entry==NULL)
							{
								cout << "out of memory" << endl;exit(1);
								deep_search_going=false;
								return NULL;
							}
							else
							{
								
								PosHashKey key=result.p.calc_key();
								
								entry->key=key;
								
								entry->no_moves=result.no_moves;
								
								entry->moves=move_alloc_ptr;
								
								for(int j=0;j<result.no_moves;j++)
								{
									move_buffer[move_alloc_ptr+j]=result.moves[j];
								}
								
								move_alloc_ptr+=result.no_moves;
								
								entry->sort_moves();
								
								entry->save();
								
							}
						}
					}
					else
					{
						cout << "position already searched" << endl;
					}
					
					no_jobs--;
					
				}
				else
				{
					Sleep(10);
				}
				
			}
			
			analysis_t.stop_timer();
			
			double elapsed=analysis_t.elapsed_time();
			
			cout << "all results arrived within " << (int)(elapsed/1000) << " sec " << endl;
			if(elapsed>30000)
			{
				max_generated_nodes-=NUM_THREADS;
				if(max_generated_nodes<NUM_THREADS){max_generated_nodes=NUM_THREADS;}
				cout << "max generated nodes adjusted down to " << max_generated_nodes << endl;
				
			}
			if(elapsed<20000)
			{
				max_generated_nodes+=NUM_THREADS;
				if(max_generated_nodes>(MAX_GENERATED_NODES-NUM_THREADS)){max_generated_nodes=MAX_GENERATED_NODES-NUM_THREADS;}
				cout << "max generated nodes adjusted up to " << max_generated_nodes << endl;
			}
			cout << "minimaxing to depth " << minimax_depth
			<< " ( positions in memory " << position_hash.value_alloc_ptr << " ) " << endl;
			
			MyTimer minimax_t;
			
			analyzers[NODE_SELECT_ANALYZER].minimax_out(deep_search_position);
			
			minimax_t.stop_timer();
			
			elapsed=minimax_t.elapsed_time();
			
			cout << "minimax took " << (int)(elapsed/1000) << " sec " << endl;
			
			if(elapsed>10000)
			{
				minimax_depth--;
				if(minimax_depth<5){minimax_depth=5;}
				cout << "minimax depth adjusted down to " << minimax_depth << endl;
				
			}
			
			if(elapsed<5000)
			{
				minimax_depth++;
				if(minimax_depth>SETUP_MAX_MINIMAX_DEPTH){minimax_depth=SETUP_MAX_MINIMAX_DEPTH;}
				cout << "minimax depth adjusted up to " << minimax_depth << endl;
			}
			
			cout << endl;
			
			analyzers[NODE_SELECT_ANALYZER].list_move_values(deep_search_position);
			
			cout << endl;
			
			Sleep(500);
			
		}while(!quit_deep_search);
		
		deep_search_going=false;
		
		return NULL;

	}
	
	void quit_deep_search_safe()
	{
		quit_deep_search=true;
		while(deep_search_going)
		{
			Sleep(50);
		}
		quit_deep_search=false;
	}
	
	void deep_search(Position p)
	{
		deep_search_position=p;
		
		if(pthread_create(&deep_search_thread, NULL, deep_search_thread_func, NULL))
		{
		
			cout << "Error creating thread." << endl;
			exit(1);

		}
	}
	
	bool Analyzer::add_node(Position p)
	{
		if(!select_node(p))
		{
			return false;
		}
		
		cout 
		<< endl 
		<< "positions " << position_hash.value_alloc_ptr << " "
		<< "examining ";
		
		for(int i=0;i<node_move_list_ptr;i++)
		{
			cout << node_move_list[i].algeb() << " ";
		}
		
		cout << endl << endl;
		
		search_move_values_safe(search_position);
		
		return true;
		
	}
	
	bool Analyzer::select_node_recursive(Depth depth,Position p)
	{
		//DeepHashValue* entry=position_hash.look_up((PositionTrunk*)&p,DONT_CREATE);
		DeepHashValue* entry=smart_look_up(p);
		
		if(entry==NULL)
		{
			//cout << "position found at " << (int)depth << endl;
			search_position=p;
			//p.print_board();
			return true;
		}
		
		if(depth>deep_search_depth)
		{
			//cout << "max depth reached at " << (int)depth << endl;
			return false;
		}
		
		if(entry->no_moves==0)
		{
			//cout << "terminal position reached at " << (int)depth << endl;
			return false;
		}
		
		int rlimit=DEEPNESS+depth*DEPTH_BONUS;
		
		// correct limit if there are only a few moves
		
		int moves_before_cutoff=0;
		for(int i=0;i<entry->no_moves;i++)
		{
			if(move_buffer[entry->moves+i].eval>CUTOFF)
			{
				moves_before_cutoff++;
			}
			else
			{
				break;
			}
		}
		
		if(moves_before_cutoff>0)
		{
			int corrlimit=150/moves_before_cutoff;
			if(rlimit<corrlimit)
			{
				rlimit=corrlimit;
			}
		}
		
		int mainr=rand()%100;
		
		if(mainr<65)
		{
			rlimit+=65;
		}
		
		for(int i=0;i<entry->no_moves;i++)
		{
			int r=rand()%100;
			
			Move m=move_buffer[entry->moves+i].m;
			
			/*cout 
			<< "move " << m.algeb() << " "
			<< "depth " << (int)depth << " "
			<< "i " << i << " "
			<< "r " << r << " "
			<< "rlimit " << rlimit << " "
			<< endl;*/
			
			bool cutoff=false;
			if(i<(entry->no_moves-1))
			{
				Score next_best=move_buffer[entry->moves+i+1].eval;
				if(next_best<CUTOFF)
				{
					cutoff=true;
				}
			}
			
			if(
				(r<rlimit)
				||
				(i==(entry->no_moves-1))
				||
				(cutoff)
			)
			{
				Position dummy=p;
				node_move_list[node_move_list_ptr++]=m;
				dummy.make_move(m);
				return select_node_recursive(depth+1,dummy);
			}
		}
		
		return false;
	}
	
	bool Analyzer::select_node(Position p)
	{
		node_move_list_ptr=0;
		return select_node_recursive(0,p);
	}
	
	Score Analyzer::minimax_recursive(Depth depth,Position p)
	{
	
		DeepHashValue* entry;
		
		if(minimax_smart)
		{
			entry=smart_look_up(p);
		}
		else
		{
			entry=position_hash.look_up((PositionTrunk*)&p,DONT_CREATE);
		}
		
		if(entry==NULL)
		{
			return INFINITE_SCORE;
		}
		
		if(depth>=(minimax_depth-minimax_depth_corr))
		{
			return INFINITE_SCORE;
		}
		
		if(entry->no_moves==0)
		{
			return INFINITE_SCORE;
		}
		
		rep_keys[depth]=entry->key;
		
		if(depth>=2)
		{
			for(int i=depth-2;i>=0;i-=2)
			{
				if(rep_keys[i]==entry->key)
				{
					//cout << "repetition detected during minimax" << endl;
					return DRAW_SCORE;
				}
			}
		}
		
		Score score=-INFINITE_SCORE;
		
		for(int i=0;i<entry->no_moves;i++)
		{
		
			Position dummy=p;
			
			DeepHashMove dm=move_buffer[entry->moves+i];
			
			Move m=dm.m;
			
			dummy.make_move(m);
			
			Score eval=-minimax_recursive(depth+1,dummy);
			
			if(eval==-INFINITE_SCORE)
			{
				eval=dm.original_search_score;
			}
			
			move_buffer[entry->moves+i].eval=eval;
			
			if(eval>score)
			{
				score=eval;
			}
			
		}
		
		entry->sort_moves();
		
		return score;
	
	}
	
	void Analyzer::minimax_out(Position p)
	{
		
		minimax_recursive(0,p);
		
	}
	
	int cmp_moves(const void* a,const void* b)
	{
		return( ((DeepHashMove*)b)->eval - ((DeepHashMove*)a)->eval );
	}
	
	void DeepHashValue::sort_moves()
	{
		qsort(&move_buffer[moves],no_moves,sizeof(DeepHashMove),cmp_moves);
	}
	
	char calc_pv_buffer[1000];
	char* calc_pv_recursive(Depth depth,Position p)
	{
	
		if(depth>minimax_depth)
		{
			return calc_pv_buffer;
		}
		
		DeepHashValue* entry=position_hash.look_up((PositionTrunk*)&p,DONT_CREATE);
		
		if(entry==NULL)
		{
			return calc_pv_buffer;
		}
		
		Move m=move_buffer[entry->moves].m;
		strcat(calc_pv_buffer,m.algeb());
		strcat(calc_pv_buffer," ");
		
		Position dummy=p;
		dummy.make_move(m);
		
		return calc_pv_recursive(depth+1,dummy);
		
	}
	
	string calc_pv(Position p)
	{
		calc_pv_buffer[0]=0;
		return calc_pv_recursive(0,p);
	}
	
	void Analyzer::list_move_values(Position p)
	{
		DeepHashValue* entry=smart_look_up(p);
		
		if(entry==NULL)
		{
			cout << "position not found in database" << endl;
			return;
		}
		
		if(entry->no_moves==0)
		{
			cout << "position in database has no legal moves" << endl;
			return;
		}
		
		entry->sort_moves();
		
		for(int i=0;i<entry->no_moves;i++)
		{
			MyHashPtr move_ptr=entry->moves+i;
			
			if(i<MAX_LISTED_MOVES)
			{
				Move m=move_buffer[move_ptr].m;
				Score original_search_score=move_buffer[move_ptr].original_search_score;
				Score eval=move_buffer[move_ptr].eval;
				
				printf("%5s %5d ( %5d ) ",m.algeb(),eval,original_search_score);
				
				Position dummy=p;
				dummy.make_move(m);
				
				cout << calc_pv(dummy);
				
				cout << endl;
			}
		}
		
	}
	
	void Analyzer::search_move_values(Position p,DeepHashValue* entry)
	{
		entry->no_moves=0;
		entry->moves=move_alloc_ptr;
		
		entry->key=p.calc_key();
		
		p.init_move_generator();
		
		while(p.next_legal_move())
		{
		
			Position dummy=p;
			dummy.make_move(p.try_move);
			
			if(search_move_values_verbose)
			{
				cout << "searching " << p.try_move.algeb() << " ";
			}
			
			search_depth=4;
			search_position=dummy;
			
			search_grad_verbose=false;
			Score score=-search_grad_call();
			search_grad_verbose=true;
			
			if(search_move_values_verbose)
			{
				cout << score << endl;
			}
			
			move_buffer[move_alloc_ptr].m=p.try_move;
			move_buffer[move_alloc_ptr].original_search_score=score;
			move_buffer[move_alloc_ptr].eval=score;
			
			move_alloc_ptr++;
			entry->no_moves++;
			
		}
		
		entry->sort_moves();
		
		entry->save();
	}
	
	void Analyzer::search_move_values_safe(Position p)
	{
		DeepHashValue* entry=position_hash.look_up((PositionTrunk*)&p,DONT_CREATE);
		
		if(entry==NULL)
		{
			if(move_alloc_ptr>=DEEP_MAX_MOVE_BUFFER_PTR)
			{
				cout << "out of memory" << endl;exit(1);
				return;
			}
			else
			{
				entry=position_hash.look_up((PositionTrunk*)&p,DO_CREATE);
				
				if(entry==NULL)
				{
					cout << "out of memory" << endl;exit(1);
					return;
				}
				else
				{
					search_move_values(p,entry);
				}
			}
		}
		
	}

	void* search_grad_thread_func(void* void_ptr)
	{

		((Analyzer*)(void_ptr))->search_grad_call();
		
		return NULL;

	}
	
	Score Analyzer::search_grad_call()
	{
		
		Score score;
		
		if(search_grad_verbose)
		{
			//cout << "search to depth " << (int)search_depth << endl;
		}
		
		for(int grad_depth=1;grad_depth<=search_depth;grad_depth++)
		{
		
			if(quit_search)
			{
				search_going=false;
				return INFINITE_SCORE;
			}
			
			verbose=false;
			
			score=search(search_position,grad_depth);
			
		}
		
		if(search_grad_verbose)
		{
			//cout << endl;
		}
		
		search_going=false;
		
		return score;
		
	}
	
	void Analyzer::quit_search_safe()
	{
		quit_search=true;
		while(search_going)
		{
			Sleep(50);
		}
		quit_search=false;
	}
	
	Score Analyzer::search_grad(Position set_search_position,Depth set_search_depth)
	{
	
		search_position=set_search_position;
		search_depth=set_search_depth;
		
		quit_search=false;
		search_going=true;
		
		if(pthread_create(&search_grad_thread, NULL, search_grad_thread_func, this))
		{

			cout << "Error creating thread." << endl;
			exit(1);

		}
		
		return 0;
		
	}
	
	Score Analyzer::search_multi()
	{
	
		nodes=0;
		
		Score score;
		
		#ifndef SEARCH_MULTI
		score=search_alphabeta(alphabeta_position,0,-INFINITE_SCORE,INFINITE_SCORE);
		best_move_multi=best_move;
		return score;
		#endif
		
		Position p=alphabeta_position;
		
		p.init_move_generator();
		
		EvalMove* entry=look_up_move(p);

		if(entry!=NULL)
		{
			p.set_search_move(entry->m);
		}
		
		if(!p.next_legal_move())
		{
			
			if(p.is_in_check(p.turn))
			{
			
				return -MATE_SCORE;
				
			}
			else
			{
			
				return DRAW_SCORE;
			
			}
			
		}
		
		global_alpha=-INFINITE_SCORE;
		
		score=-INFINITE_SCORE;
		
		int num_legal_moves=0;
		do
		{
		
			num_legal_moves++;
	
			Position dummy=p;
			
			dummy.make_move(p.try_move);
			
			SearchJob search_job;
			
			search_job.p=dummy;
			
			search_job.multi=true;
			search_job.m=p.try_move;
			search_job.depth=alphabeta_depth;
			
			strcpy(search_job.line,p.try_move.algeb());
			
			position_queue.enqueue(&search_job);
		
		}while(p.next_legal_move());
		
		while(num_legal_moves)
		{
		
			if(quit_search)
			{
				global_quit_search=true;
			}
		
			if(result_queue.pending())
			{

				SearchResult result;
				result_queue.dequeue(&result);
				
				num_legal_moves--;
				
				Score eval=-result.score;
				
				nodes+=result.nodes;
				
				if(eval>score)
				{
				
					best_move_multi=result.m;
				
					score=eval;
					
					global_alpha=score;
					
					store_move(p,result.m,0,score);
				}

			}
			
			Sleep(5);
			
		}
		
		global_alpha=-INFINITE_SCORE;
		
		if(quit_search)
		{
			
			return INFINITE_SCORE;
		}
		
		return score;
	}
	
	Score Analyzer::search(Position set_alphabeta_position,Depth set_alphabeta_depth)
	{
	
		global_quit_search=false;
	
		alphabeta_position=set_alphabeta_position;
	
		alphabeta_depth=set_alphabeta_depth;
		
		nodes=0;
		
		MyTimer alphabeta_t;

		#ifdef SEARCH_MULTI
		alphabeta_depth--;
		#endif
		
		Score score=search_multi();
		
		#ifdef SEARCH_MULTI
		alphabeta_depth++;
		#endif
		
		if(quit_search)
		{
			return INFINITE_SCORE;
		}
		
		alphabeta_t.stop_timer();
		
		double elapsed=alphabeta_t.elapsed_time();
		
		double nps;
		
		if(elapsed>0)
		{
			nps=(double)nodes/elapsed;
		}
		else
		{
			nps=0.0;
		}
		
		elapsed/=1000.0;
		
		if(search_grad_verbose)
		{
		
			#ifdef WINBOARD
			
			printf("%d %d %d %d %s\n",(int)alphabeta_depth,(int)score,(int)elapsed,(int)nodes,best_move_multi.algeb());
			
			#else
			
			printf("%2d  %-5s %4d  time %4d  nodes %9d  nps  %4.1f",(int)alphabeta_depth,best_move_multi.algeb(),score,(int)elapsed,nodes,nps);
			
			cout << endl;
			
			#endif

		}
		
		return score;
	
	}
	
	Score Analyzer::search_alphabeta(Position p,Depth depth,Score alpha,Score beta)
	{
		
		int no_searched_moves=0;
		
		int score=-INFINITE_SCORE;
		
		if(depth<alphabeta_depth)
		{
		
			p.init_move_generator();
			
			#ifdef SEARCH_MULTI
			for(int a=0;a<NUM_THREADS;a++)
			{
				EvalMove* entry=analyzers[a].look_up_move(p);
				
				if(entry!=NULL)
				{
					p.set_search_move(entry->m);
					break;
				}
			}
			#else
			EvalMove* entry=look_up_move(p);
				
			if(entry!=NULL)
			{
				p.set_search_move(entry->m);
			}
			#endif
		
			while(p.next_legal_move())
			{
			
				Position dummy=p;
				
				dummy.make_move(p.try_move);
				
				if(verbose)
				{
					if(depth==0)
					{
						cout
						<< p.try_move.algeb() << " ";
					}
				}
				
				int eval=-search_alphabeta(dummy,depth+1,-beta,-alpha);
				if((quit_search)||(global_quit_search))
				{
					return INFINITE_SCORE;
				}
				
				no_searched_moves++;
				
				if(eval>score)
				{
					score=eval;
					
					if(depth==0)
					{
					
						if(verbose)
						{
						
							cout
							<< (int)eval
							<< endl;
						
						}
						
						best_move=p.try_move;
						
					}
				}
				else
				{
					if(verbose)
					{
					
						if(depth==0)
						{
						
							cout
							<< "ref"
							<< endl;
						
						}
						
					}
				}
				
				if(score>alpha)
				{
					alpha=score;
					
					store_move(p,p.try_move,depth,score);
				}
				
				if(alpha>beta)
				{
					
					return score;
					
				}
				
			}
			
		}
		
		if(no_searched_moves==0)
		{
		
			nodes++;
		
			p.init_move_generator();
		
			if(p.next_legal_move())
			{
			
				return p.relative_heuristic_value();
			
			}
			else
			{
				
				if(p.is_in_check(p.turn))
				{
				
					return -MATE_SCORE+depth;
					
				}
				else
				{
				
					return DRAW_SCORE;
				
				}
				
			}
		
		}
		
		return score;
	
	}
	
	void Analyzer::store_move(Position p,Move m,Depth depth,Score score)
	{
	
		EvalMove* entry=move_hash->look_up((PositionTrunk*)&p);
		
		if(entry->used)
		{
			if(entry->depth<depth)
			{
				return;
			}
		}
		
		entry->used=true;
		memcpy(entry->trunk,(PositionTrunk*)&p,sizeof(PositionTrunk));
		entry->m=m;
		entry->depth=depth;
		entry->score=score;
		
	}
	
	EvalMove* Analyzer::look_up_move(Position p)
	{
		EvalMove* entry=move_hash->look_up((PositionTrunk*)&p);
		
		if(!entry->used)
		{
			return NULL;
		}
		
		if(0==memcmp(entry->trunk,(PositionTrunk*)&p,sizeof(PositionTrunk)))
		{
			return entry;
		}
		else
		{
			return NULL;
		}
	}
	
	void save_hash()
	{
		ofstream o("hash.dat",ios::binary);
		o.write((char*)&position_hash.value_alloc_ptr,sizeof(int));
		o.write((char*)position_hash.hash_ptrs,position_hash.ptrs_buffer_size);
		o.write((char*)position_hash.hash_values,position_hash.value_buffer_size);
		o.write((char*)&move_alloc_ptr,sizeof(MyHashPtr));
		o.write((char*)&move_buffer,sizeof(move_buffer));
		o.close();
	}

	void load_hash()
	{
		ifstream i("hash.dat",ios::binary);
		i.read((char*)&position_hash.value_alloc_ptr,sizeof(int));
		i.read((char*)position_hash.hash_ptrs,position_hash.ptrs_buffer_size);
		i.read((char*)position_hash.hash_values,position_hash.value_buffer_size);
		i.read((char*)&move_alloc_ptr,sizeof(MyHashPtr));
		i.read((char*)&move_buffer,sizeof(move_buffer));
		i.close();
	}
	
	char DeepHashValue_file_name_buffer[1000];
	char* DeepHashValue::file_name()
	{
		strcpy(DeepHashValue_file_name_buffer,"Data\\");
		std::ostringstream oss;
		oss << "Data\\" << key << ".dat";
		strcpy(DeepHashValue_file_name_buffer,oss.str().c_str());
		return DeepHashValue_file_name_buffer;
	}
	
	int DeepHashValue::move_buffer_size()
	{
		return no_moves*sizeof(DeepHashMove);
	}
	
	void DeepHashValue::save()
	{
		//cout << "saving " << file_name() << endl;
		ofstream o(file_name(),ios::binary);
		o.write((char*)this,sizeof(DeepHashValue));
		o.write((char*)&move_buffer[moves],move_buffer_size());
		o.close();
	}
	
	void export_deep_hash()
	{
	
		for(int i=0;i<position_hash.value_alloc_ptr;i++)
		{
			position_hash.hash_values[i].save();
		}
		
	}
	
	int num_deep_positions()
	{
		return position_hash.value_alloc_ptr-1;
	}
	
	void erase_hash()
	{
		position_hash.init();
		move_alloc_ptr=0;
	}
	
}