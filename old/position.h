#ifndef POSITION_H
#define POSITION_H

#include <cstddef>

#include "setup.h"

using namespace std;

namespace PositionSpace
{

	//#define DEBUG_MOVE_TABLE

	///////////////////////////////////////////////////
	// basic definitions to set up the board
	
	typedef unsigned char Depth;
	typedef unsigned char Piece;
	typedef unsigned char PieceColor;
	typedef unsigned char Square;
	typedef unsigned char Turn;
	typedef unsigned char Size;
	typedef unsigned char Mask;
	typedef unsigned char File;
	typedef unsigned char Rank;
	typedef unsigned char CastlingRight;
	
	const Size BOARD_WIDTH_SHIFT=(3);
	const Size BOARD_WIDTH=(1 << BOARD_WIDTH_SHIFT);
	const File BOARD_LAST_FILE_INDEX=(BOARD_WIDTH - 1);
	const Mask FILE_MASK=(BOARD_LAST_FILE_INDEX);
	const Size BOARD_HEIGHT_SHIFT=(3);
	const Size BOARD_HEIGHT=(1 << BOARD_HEIGHT_SHIFT);
	const Rank BOARD_LAST_RANK_INDEX=(BOARD_HEIGHT - 1);
	const Mask RANK_MASK=(BOARD_LAST_RANK_INDEX << BOARD_WIDTH_SHIFT);
	
	const Size BOARD_SIZE=(BOARD_WIDTH * BOARD_HEIGHT);
	
	const Turn TURN_WHITE=(1);
	const Turn WHITE=TURN_WHITE;
	const Turn TURN_BLACK=(0);
	const Turn BLACK=TURN_BLACK;
	
	const Square SQUARE_NONE=(1 << (BOARD_WIDTH_SHIFT+BOARD_HEIGHT_SHIFT));
	
	///////////////////////////////////////////////////
	
	///////////////////////////////////////////////////////////////////////////////////
	// pieces
	
	const Piece SLIDING_PIECE=(1 << 2);
	const Piece DIAGONAL_PIECE=(1 << 1);
	const Piece STRAIGHT_PIECE=(1 << 0);
	
	// no piece
	const Piece NO_PIECE=(0);											// 0

	// non sliding pieces
	const Piece KING=(1 << 0);											// 1
	const Piece KNIGHT=(1 << 1);										// 2
	
	// pawn is defined king + knight
	const Piece PAWN=(KING|KNIGHT);										// 3

	// void piece is defined as a sliding piece which cannot move in any direction
	// it has king moves without castling moves
	// used for calculating capture explosion squares, adjacent kings and attacked squares around king
	const Piece VOID_PIECE=(SLIDING_PIECE);								// 4

	// sliding pieces
	const Piece ROOK=(SLIDING_PIECE|STRAIGHT_PIECE);					// 5
	const Piece BISHOP=(SLIDING_PIECE|DIAGONAL_PIECE);					// 6
	const Piece QUEEN=(SLIDING_PIECE|STRAIGHT_PIECE|DIAGONAL_PIECE);	// 7
	
	const Piece WHITE_PIECE=(1 << 3);
	const Piece BLACK_PIECE=(0);
	
	const char piece_letters[]=".knp.rbq.KNP.RBQ";
	
	///////////////////////////////////////////////////////////////////////////////////
	
	///////////////////////////////////////////////////////////////////////////////////
	// castling rights
	
	const CastlingRight CASTLING_RIGHT_K=(1 << 3);
	const CastlingRight CASTLING_RIGHT_Q=(1 << 2);
	const CastlingRight CASTLING_RIGHT_W=CASTLING_RIGHT_K|CASTLING_RIGHT_Q;
	
	const CastlingRight CASTLING_RIGHT_k=(1 << 1);
	const CastlingRight CASTLING_RIGHT_q=(1);
	const CastlingRight CASTLING_RIGHT_b=CASTLING_RIGHT_k|CASTLING_RIGHT_q;
	
	const CastlingRight CASTLING_RIGHT_NONE=(0);
	
	const CastlingRight CASTLING_RIGHT_DISABLE_SQUARE_K=(63);
	const CastlingRight CASTLING_RIGHT_DISABLE_SQUARE_Q=(56);
	const CastlingRight CASTLING_RIGHT_DISABLE_SQUARE_k=(7);
	const CastlingRight CASTLING_RIGHT_DISABLE_SQUARE_q=(0);
	
	///////////////////////////////////////////////////////////////////////////////////
	// macro functions
	
	#define ALGEB_RANK_OF(RANK) ('1' + BOARD_LAST_RANK_INDEX - RANK)
	#define ALGEB_FILE_OF(FILE) ('a' + FILE)
	
	#define SQUARE_FROM_RANK_FILE(RANK,FILE)  ((RANK) * BOARD_WIDTH + FILE)
	
	#define NAME_OF_TURN(TURN) (TURN==TURN_WHITE?"white":"black")
	#define NAME_OF_COLOR(COLOR) NAME_OF_TURN(COLOR)
	
	#define FILE_OF_SQUARE(SQUARE) (SQUARE & FILE_MASK)
	#define RANK_OF_SQUARE(SQUARE) ((SQUARE & RANK_MASK) >> BOARD_WIDTH_SHIFT)
	
	///////////////////////////////////////////////////////////////////////////////////
	
	///////////////////////////////////////////////////
	// move generation
	
	typedef unsigned int MoveType;
	
	struct MoveDescriptor
	{
		Square to_sq;
		MoveType type;
		int next_vector;
	};
	
	const MoveType END_PIECE=(0);
	
	typedef unsigned char PieceCount;
	typedef unsigned short int MoveCount;
	
	const PieceCount NUM_PIECES=WHITE_PIECE;
	const PieceCount TOTAL_NUM_PIECES=(2*WHITE_PIECE);
	
	const MoveCount AVERAGE_NUMBER_OF_LEGAL_MOVES_PER_POSITION=35;
	const MoveCount MAXIMUM_NUMBER_OF_LEGAL_MOVES_PER_POSITION=350;
	const MoveCount MAXIMUM_NUMBER_OF_LEGAL_MOVES_PER_PIECE=30;
	const MoveCount AVERAGE_NUMBER_OF_LEGAL_MOVES_PER_PIECE=10;
	const int MOVE_TABLE_SIZE=(2*NUM_PIECES*BOARD_SIZE*AVERAGE_NUMBER_OF_LEGAL_MOVES_PER_PIECE);
	
	typedef unsigned char Color;
	
	#define RANK_OK(RANK) ((RANK>=0)&&(RANK<=BOARD_LAST_RANK_INDEX))
	#define FILE_OK(FILE) ((FILE>=0)&&(FILE<=BOARD_LAST_FILE_INDEX))
	#define RANK_FILE_OK(RANK,FILE) (RANK_OK(RANK) && FILE_OK(FILE))
	
	const MoveType SLIDING_MOVE=(1 << 8);
	const MoveType SINGLE_MOVE=(1 << 9);
	const MoveType KING_MOVE=(1 << 10);
	const MoveType CASTLING_MOVE=(1 << 11);
	const MoveType PAWN_MOVE=(1 << 12);
	const MoveType PAWN_PUSH_MOVE=(1 << 13);
	const MoveType PAWN_PUSH_BY_ONE_MOVE=(1 << 14);
	const MoveType PAWN_PUSH_BY_TWO_MOVE=(1 << 15);
	const MoveType PAWN_CAPTURE_MOVE=(1 << 16);
	const MoveType CAPTURE_MOVE=(1 << 17);
	const MoveType PROMOTION_MOVE=(1 << 18);
	const MoveType EP_CAPTURE_MOVE=(1 << 19);
	const MoveType CASTLING_KING_SIDE_MOVE=(1 << 20);
	const MoveType CASTLING_QUEEN_SIDE_MOVE=(1 << 21);
	
	const MoveType SPECIAL_MOVE=(PAWN_PUSH_BY_TWO_MOVE | PROMOTION_MOVE | CASTLING_MOVE);

	const Square CASTLE_FROM_SQUARE_WHITE=(60);
	const Square CASTLE_FROM_SQUARE_BLACK=(4);
	
	#define BASE_RANK(COLOR) (((COLOR)==WHITE)?(6):(1))
	#define PROMOTION_RANK(COLOR) (((COLOR)==WHITE)?(1):(6))
	#define INFO_OF_TYPE(TYPE) ((TYPE) & ((1 << 8) - 1))
	
	const Piece PROMOTION_PIECES[4]={KNIGHT,BISHOP,ROOK,QUEEN};
	
	#ifdef VARIANT_ATOMIC
	const Piece CHECKING_PIECES[]={KNIGHT,BISHOP,ROOK,QUEEN,PAWN};
	const int NUM_CHECKING_PIECES=(5);
	#else
	const Piece CHECKING_PIECES[]={KNIGHT,BISHOP,ROOK,QUEEN,PAWN,KING};
	const int NUM_CHECKING_PIECES=(6);
	#endif
	
	const Piece PIECE_MASK=(WHITE_PIECE - 1);
	
	#define PIECE_OF(PIECE) ((PIECE) & PIECE_MASK)
	#define TURN_OF(PIECE) (((PIECE) & WHITE_PIECE) >> 3)
	#define COLOR_OF(PIECE) TURN_OF(PIECE)
	
	///////////////////////////////////////////////////
	
	void init();
	
	///////////////////////////////////////////////////
	
	Square algeb_to_square(const char*);
	
	///////////////////////////////////////////////////
	
	struct Move
	{
		Square from_sq;
		Square to_sq;
		MoveType type;
		
		const char* algeb();
		bool equal_to(Move);
	};
	
	///////////////////////////////////////////////////
	
	const bool COUNT_ALL=false;
	const bool FIND_FIRST=true;
	
	#define OPPOSITE_COLOR(COLOR) (1-COLOR)
	#define OPPOSITE_TURN(TURN) OPPOSITE_COLOR(TURN)
	#define PIECE_COLOR_OF_COLOR(COLOR) (COLOR==WHITE?WHITE_PIECE:BLACK_PIECE)
	
	typedef Piece PositionTrunk[BOARD_SIZE+3];
	
	typedef unsigned int PosHashKey;
	
	///////////////////////////////////////////////////
	
	struct Position
	{
	
		///////////////////////////////////////////////////
		// position trunk, used to calculate the hash key
		Piece board[BOARD_SIZE];
		Turn turn;
		Square ep_square;
		CastlingRight castling_rights;
		///////////////////////////////////////////////////
		
		int halfmove_clock;
		int fullmove_number;
		
		PosHashKey calc_key();
		PosHashKey key;
		
		Square king_pos[2];
		
		void reset();
		void set_from_fen(const char*);
		void print_board();
		
		void make_move_raw(Move);
		void make_move(Move);
		
		void print_king_status(Color);
		
		int attackers_on_square_of_color(Square,Color,bool);
		int attackers_on_king_of_color(Color);
		bool is_exploded(Color);
		bool adjacent_kings();
		bool is_in_check(Color);
		
		Square current_move_gen_sq;
		int current_move_gen_ptr;
		void init_move_generator();
		void next_move_gen_sq();
		Move try_move;
		Piece current_piece;
		bool next_pseudo_legal_move();
		bool next_legal_move();
		bool is_algeb_move_legal(const char*);
		bool is_san_move_legal(const char*);
		int count_legal_moves(Color);
		int count_pseudo_legal_moves(Color);
		int count_material_of_color(Color);
		int count_material_balance_for_color(Color);
		int heuristic_value_of(Color);
		int heuristic_value_non_material_of(Color);
		int relative_heuristic_value();
		
		bool is_in_check_square(Square,Color);
		
		bool is_search_move;
		bool search_move_done;
		Move search_move;
		void set_search_move(Move);
		
		void save();
		void load();
		
		const char* to_san(Move);
		
		int count_endgame_corr_for_color(Color);
		short int abs_mat;
		
		const char* report_fen();
		
	};
	
	///////////////////////////////////////////////////
	
	struct GameItem
	{
		Position p;
		GameItem* prev;
		GameItem* next;
	};
	
	class Game
	{
		public:
		GameItem* game;
		GameItem* current;
		void add_position(Position);
		const char* line();
		void debug();
		void init(Position p)
		{
			current=NULL;
			add_position(p);
		}
		void back()
		{
			if(current->prev!=NULL)
			{
				current=current->prev;
			}
		}
		void unback()
		{
			if(current->next!=NULL)
			{
				current=current->next;
			}
		}
		void add_san_move(const char*);
		void set_from_pgn();
		void list_fens();
		Game()
		{
			Position p;
			p.reset();
			init(p);
		}
	};

}

#endif