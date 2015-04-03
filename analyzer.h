#ifndef ANALYZER_H
#define ANALYZER_H

#include "setup.h"

#include "position.h"

#include "utils/include/pthread.h"
#include "utils/include/myhash.h"

#include <iostream>

using namespace std;
using namespace PositionSpace;
using namespace MyHashSpace;

namespace AnalyzerSpace
{

	const int MAX_GENERATED_NODES=(20 * NUM_THREADS);

	const int QUEUE_LENGTH=(MAXIMUM_NUMBER_OF_LEGAL_MOVES_PER_POSITION);
	const int MAX_LISTED_MOVES=(SETUP_MAX_LISTED_MOVES);

	extern pthread_mutex_t display_mutex;

	extern void quit_deep_search_safe();
	extern void deep_search(Position);
	
	extern void export_deep_hash();
	
	extern bool minimax_smart;

	typedef short int Score;
	
	const Score DRAW_SCORE=0;
	const Score MATE_SCORE=10000;
	const Score INFINITE_SCORE=10001;

	void init();
	
	struct DeepHashMove
	{
	
		Move m;
		
		Score original_search_score;
		Score eval;
		
	};
	
	struct DeepHashValue
	{
		PositionTrunk id;
		MyHashPtr next;
		
		MyHashPtr moves;
		int no_moves;
		
		PosHashKey key;
		
		void sort_moves();
		char* file_name();
		int move_buffer_size();
		void save();
	};
	
	struct SearchJob
	{
		Position p;
		char line[1000];
		
		bool multi;
		Move m;
		Depth depth;
	};
	
	struct SearchResult
	{
		Position p;
		
		DeepHashMove moves[MAXIMUM_NUMBER_OF_LEGAL_MOVES_PER_POSITION];
		
		int no_moves;
		
		bool multi;
		Move m;
		Score score;
		int nodes;
	};
	
	const int DEEP_MOVE_BUFFER_SIZE=(DEEP_POSITION_BUFFER_SIZE*AVERAGE_NUMBER_OF_LEGAL_MOVES_PER_POSITION);
	const int DEEP_MAX_MOVE_BUFFER_PTR=(DEEP_MOVE_BUFFER_SIZE-MAXIMUM_NUMBER_OF_LEGAL_MOVES_PER_POSITION);
	
	struct EvalMove
	{
		PositionTrunk trunk;
		Move m;
		bool used;
		Depth depth;
		Score score;
	};
	
	const int NUM_ANALYZERS=(NUM_THREADS+2);
	
	extern KickHash <PositionTrunk,EvalMove,MOVE_HASH_SHIFT> move_hashes[NUM_ANALYZERS];
	
	const Depth MINIMAX_DEPTH=(SETUP_MINIMAX_DEPTH);
	const Depth REP_DEPTH=(SETUP_MAX_MINIMAX_PUFFER_SIZE);
	
	extern void load_hash();
	extern void save_hash();

	class Analyzer
	{
	
		public:
		
		KickHash <PositionTrunk,EvalMove,MOVE_HASH_SHIFT>* move_hash;
		
		Position search_position;
		Position alphabeta_position;
		Depth search_depth;
		Depth alphabeta_depth;
		
		int nodes;
		
		Move best_move;
		Move best_move_multi;
		
		Score search_alphabeta(Position,Depth,Score,Score);
		Score search(Position,Depth);
		Score search_multi();
		Score search_grad(Position,Depth);
		Score search_grad_call();
		
		bool verbose;
		bool search_grad_verbose;
		bool search_move_values_verbose;
		
		pthread_t search_grad_thread;
		
		void quit_search_safe();
		
		bool quit_search;
		bool search_going;
		
		void store_move(Position,Move,Depth,Score);
		EvalMove* look_up_move(Position);
		
		void search_move_values(Position,DeepHashValue*);
		void search_move_values_safe(Position);
		
		void list_move_values(Position);
		
		PosHashKey rep_keys[REP_DEPTH];
		
		Score minimax_recursive(Depth,Position);
		void minimax_out(Position);
		
		bool select_node_recursive(Depth,Position);
		bool select_node(Position);
		
		bool add_node(Position);
		
		int node_move_list_ptr;
		Move node_move_list[SETUP_MAX_MINIMAX_PUFFER_SIZE];
		
		pthread_t analyzer_thread;
		
		void start_analyzer();
		
		int num_analyzer;
		
		void enqueue_move_values(Position);
		
		Analyzer()
		{
			
			verbose=true;
			search_grad_verbose=true;
			search_move_values_verbose=false;
			quit_search=false;
			search_going=false;
			
		}
	
	};
	
	extern Analyzer analyzers[NUM_ANALYZERS];
	
	const int ALPHABETA_ANALYZER=(NUM_THREADS);
	const int NODE_SELECT_ANALYZER=(NUM_THREADS+1);
	
	extern int num_deep_positions();
	
	extern void erase_hash();

}

#endif