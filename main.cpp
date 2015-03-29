#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>

#include "utils/include/pthread.h"

using namespace std;

#include "utils/include/myhash.h"
#include "utils/include/unbufstdio.h"

#include "position.h"
#include "analyzer.h"

#include "anno.h"

#include "setup.h"

#ifdef MY_MSVC
#include <Windows.h>
#endif

#define OBSERVING_STATE 1
#define WAITING_STATE 2
#define THINKING_STATE 3
#define PONDERING_STATE 4
#define PONDER_COMPLETE_STATE 5
#define ANALYZING_STATE 6
#define ANALYSIS_COMPLETE_STATE 7

int winboard_state=OBSERVING_STATE;

PositionSpace::Position game[200];
int game_ptr;

PositionSpace::Game g;

AnalyzerSpace::Analyzer* alphabeta_analyzer;

PositionSpace::Position p;

void stdin_dequeue_callback_func(UnbufstdioSpace::Item item)
{

	ofstream o("log.txt",ios::binary|ios::app);
	if(o.is_open())
	{
		o.write((char*)&item.buffer,strlen(item.buffer));
		o.write((char*)"\r\n",2);
		o.close();
	}
	
}

void log_print(const char* l)
{
	ofstream o("log.txt",ios::app);
	if(o.is_open())
	{
		o << l << endl;
		o.close();
	}
}

void init_main()
{

	PositionSpace::init();
	AnalyzerSpace::init();
	
	#ifdef WINBOARD
	UnbufstdioSpace::init();
	UnbufstdioSpace::stdin_dequeue_callback=stdin_dequeue_callback_func;
	#endif
	
	#ifdef ALLOW_BOOK
	load_anno_book();
	#endif
	
	ofstream o("log.txt",ios::binary);
	if(o.is_open())
	{
		o.close();
	}
	
	game_ptr=-1;
	
	alphabeta_analyzer=&AnalyzerSpace::analyzers[AnalyzerSpace::ALPHABETA_ANALYZER];
	
	winboard_state=OBSERVING_STATE;
	log_print("init: OBSERVING STATE");
	
}

#ifdef WINBOARD

void make_move()
{	
	anno_verbose=false;
	list_annotated_moves(&p);
	
	Move best_move;
	
	if(is_recommended_move)
	{
		best_move=recommended_move;
	}
	else
	{
		alphabeta_analyzer->search_position=p;
		alphabeta_analyzer->search_depth=WINBOARD_DEPTH;
		alphabeta_analyzer->search_grad_call();
		
		best_move=alphabeta_analyzer->best_move_multi;
	}
	
	game[++game_ptr]=p;
	
	p.make_move(best_move);
	
	printf("move %s\n",best_move.algeb());
	
	winboard_state=PONDERING_STATE;
	log_print("move made: OBSERVING STATE");
	
}

int main(int argc,char** argv)
{

	init_main();
	
	bool quit=false;
	
	UnbufstdioSpace::Item item;
	
	p.reset();
	
	bool computer=false;
	
	do
	{
	
		Sleep(50);
	
		if(UnbufstdioSpace::stdin_pending())
		{
		
			UnbufstdioSpace::stdin_dequeue(&item);
		
			char* token;
			token=item.get_token();
			
			if(0==strcmp(token,"quit"))
			{
				quit=true;
				continue;
			}
			
			if(0==strcmp(token,"new"))
			{
				p.reset();
				game_ptr=-1;
				winboard_state=WAITING_STATE;
				log_print("new: WAITING STATE");
				continue;
			}
			
			if(0==strcmp(token,"force"))
			{
				winboard_state=OBSERVING_STATE;
				log_print("force: OBSERVING STATE");
				alphabeta_analyzer->quit_search_safe();
				continue;
			}
			
			if(0==strcmp(token,"undo"))
			{
				log_print("undo: ");
				if(game_ptr>=0)
				{
					p=game[game_ptr--];
				}
				if(
					(winboard_state==ANALYZING_STATE)
				)
				{
					log_print("undo: ANALYZING STATE");
					alphabeta_analyzer->quit_search_safe();
					alphabeta_analyzer->search_grad(p,20);
				}
				continue;
			}
			
			if(0==strcmp(token,"analyze"))
			{
				if(winboard_state==OBSERVING_STATE)
				{
					winboard_state=ANALYZING_STATE;
					log_print("analyze: ANALYZING STATE");
				}
				continue;
			}
			
			if(0==strcmp(token,"exit"))
			{
				if(winboard_state==ANALYZING_STATE)
				{
					winboard_state=OBSERVING_STATE;
					log_print("exit: OBSERVING STATE");
					alphabeta_analyzer->quit_search_safe();
				}
				continue;
			}
			
			if(0==strcmp(token,"computer"))
			{
				computer=true;
				continue;
			}
			
			if(0==strcmp(token,"usermove"))
			{
				token=item.get_token();
				if(p.is_algeb_move_legal(token))
				{
					game[++game_ptr]=p;
					p.make_move(p.try_move);
				}
				
				if(
					(winboard_state==WAITING_STATE)
					||
					(winboard_state==PONDERING_STATE)
				)
				{
					winboard_state=THINKING_STATE;
					log_print("usermove: THINKING STATE");
					make_move();
				}
				
				if(
					(winboard_state==ANALYZING_STATE)
				)
				{
					log_print("usermove: ANALYZING STATE");
					alphabeta_analyzer->quit_search_safe();
					alphabeta_analyzer->search_grad(p,20);
				}
				
				continue;
			}
			
			if(0==strcmp(token,"go"))
			{
				winboard_state=THINKING_STATE;
				log_print("go: THINKING STATE");
				make_move();
				continue;
			}
			
			if(0==strcmp(token,"protover"))
			{
				printf("feature usermove=1\n");
				printf("feature done=1\n");
				continue;
			}
		
		}
		
	}while(!quit);
	
}

#else

int main(int argc,char** argv)
{

	init_main();
	
	char buf[200];
	string message="";
	
	p.reset();
	
	bool print_prompt=true;
	bool list_move_values=false;
	
	do
	{
	
		cout << endl;
	
		if(print_prompt)
		{
		
			pthread_mutex_lock(&AnalyzerSpace::display_mutex);
		
			p.print_board();
			
			cout << endl << "line: " << g.line() << endl;
			
			//if(list_move_values)
			{
				cout << endl;
				alphabeta_analyzer->list_move_values(p);
				list_move_values=false;
			}
			
			anno_verbose=true;
			list_annotated_moves(&p);
			anno_verbose=false;
			
			cout << endl << message << " [ pos " << AnalyzerSpace::num_deep_positions() << " ] > ";
			
			pthread_mutex_unlock(&AnalyzerSpace::display_mutex);
		}
		
		print_prompt=true;
		message="";
	
		cin.getline(buf,200);
		
		cout << endl;
		
		if(0==strcmp(buf,"ad"))
		{
			set_anno_default();
			message="default annotations set";
			continue;
		}

		if(buf[0]=='o')
		{

			if((buf[5]=='=')||(buf[6]=='='))
			{
				char* annot;
				if(buf[5]=='=')
				{
					buf[5]=0;
					annot=buf+6;
				}
				else
				{
					buf[6]=0;
					annot=buf+7;
				}

				if(annotate_move(&p,buf+1,annot))
				{
					message="move annotated ok";
				}
				else
				{
					message="error annotating move ( possible causes: move invalid or out of memory )";
				}
			}
			else
			{
				message="wrong annotation syntax, use n[algeb]=[annotation]";
			}

		}

		
		if(0==strcmp(buf,"sa"))
		{
			AnalyzerSpace::save_hash();
			p.save();
			message="deep hash saved";
			continue;
		}
		
		if(0==strcmp(buf,"li"))
		{
			list_move_values=true;
			message="move values listed";
			continue;
		}
		
		if(0==strcmp(buf,"er"))
		{
			AnalyzerSpace::erase_hash();
			message="hash erased";
			continue;
		}
		
		if(0==strcmp(buf,"ex"))
		{
			AnalyzerSpace::export_deep_hash();
			message="deep hash exported";
			continue;
		}
		
		if(0==strcmp(buf,"lo"))
		{
			AnalyzerSpace::load_hash();
			p.load();
			g.init(p);
			message="deep hash loaded";
			continue;
		}
		
		if(0==strcmp(buf,"q"))
		{
			alphabeta_analyzer->quit_search_safe();
			message="alphabeta search quitted";
			continue;
		}
		
		if(0==strcmp(buf,"qd"))
		{
			AnalyzerSpace::quit_deep_search_safe();
			message="deep search quitted";
			continue;
		}
		
		if(buf[0]=='s')
		{
			print_prompt=false;
			alphabeta_analyzer->search_grad(p,(buf[1]-'0'));
			message="search started";
			continue;
		}
		
		if(buf[0]=='i')
		{
			print_prompt=false;
			alphabeta_analyzer->search_grad(p,20);
			message="infinite search started";
		}

		#ifndef SEARCH_MULTI
		if(buf[0]=='d')
		{
			print_prompt=false;
			message="deep search started";
			AnalyzerSpace::deep_search(p);
			continue;
		}
		#else
		if(buf[0]=='d')
		{
			message="deep search not supported with multi search";
			continue;
		}
		#endif
		
		if(buf[0]=='v')
		{
			alphabeta_analyzer->search_move_values_safe(p);
			message="move values searched";
			list_move_values=true;
			continue;
		}
		
		if(buf[0]=='n')
		{
			AnalyzerSpace::minimax_smart=true;
			alphabeta_analyzer->minimax_out(p);
			AnalyzerSpace::minimax_smart=false;
			message="tree minimaxed out";
			continue;
		}
		
		if(buf[0]=='k')
		{
			alphabeta_analyzer->add_node(p);
			message="node added";
			continue;
		}
	
		if(buf[0]=='m')
		{
		
			if((p.is_algeb_move_legal(buf+1))||(p.is_san_move_legal(buf+1)))
			{
				p.make_move(p.try_move);
				g.add_position(p);
				message="move made ok";
			}
			else
			{
				message="illegal move";
			}
			continue;
			
		}
		
		if(buf[0]=='p')
		{
		
			PositionSpace::Move m;
			m.from_sq=PositionSpace::algeb_to_square((const char*)(buf+1));
			m.to_sq=PositionSpace::algeb_to_square((const char*)(buf+3));
			m.type=0;
			p.make_move(m);
			g.add_position(p);
			message="move made by force ok";
			continue;
		}
		
		if(buf[0]=='f')
		{
			#ifdef MY_MSVC
			OpenClipboard(NULL);
			char fen[200];
			strncpy_s(fen, (char*)GetClipboardData(CF_TEXT),200);
			CloseClipboard();
			p.set_from_fen(fen);
			#else
			p.set_from_fen(buf+1);
			#endif
			g.init(p);
			message="position set from fen";
			continue;
		}
		
		if(buf[0]=='u')
		{
			if(buf[1]=='u')
			{
				if(g.current->next!=NULL)
				{
					g.unback();
					
					p=g.current->p;
					
					message="move remade";
				}
				else
				{
					message="no move to remake";
				}
				
			}
			else
			{
	
				if(g.current->prev!=NULL)
				{
					g.back();
					
					p=g.current->p;
					
					message="move unmade";
				}
				else
				{
					message="no move to unmake";
				}
				
			}
			continue;
		}
		
		if(buf[0]=='r')
		{
		
			p.reset();

			g.init(p);
			
			message="board resetted";
			continue;
			
		}
		
		if(buf[0]=='l')
		{
			p.init_move_generator();
			int count=0;
			while(p.next_legal_move())
			{
				cout 
				<< p.try_move.algeb() << " "
				<< p.to_san(p.try_move)
				<< endl;
				count++;
			}
			
			message="number of moves ";
			ostringstream ss;
			ss << count;
			message+=ss.str();
			continue;
		}
	
	}while(buf[0]!='x');
	
	return 0;

}

#endif