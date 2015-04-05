#include "position.h"

#include "utils/include/xxhash.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

namespace PositionSpace
{

	int material_values[TOTAL_NUM_PIECES];
	
	void init_material_values()
	{
		for(int i=0;i<=1;i++)
		{
			PieceColor piece_color=(i==1?WHITE_PIECE:BLACK_PIECE);
			int sign=(i==1?1:-1);
			material_values[piece_color|KING]=0;
			material_values[piece_color|PAWN]=sign*PAWN_VALUE;
			material_values[piece_color|KNIGHT]=sign*KNIGHT_VALUE;
			material_values[piece_color|BISHOP]=sign*BISHOP_VALUE;
			material_values[piece_color|ROOK]=sign*ROOK_VALUE;
			material_values[piece_color|QUEEN]=sign*QUEEN_VALUE;
		}
	}

	int move_table_init_current_ptr;
	int move_table_ptr[2][NUM_PIECES][BOARD_SIZE];
	
	MoveDescriptor move_table[MOVE_TABLE_SIZE];
	
	Square algeb_to_square(const char* algeb)
	{
		if((algeb[0]<'a')||(algeb[0]>('a'+BOARD_WIDTH-1))){return SQUARE_NONE;}
		if((algeb[1]<'1')||(algeb[1]>('1'+BOARD_HEIGHT-1))){return SQUARE_NONE;}

		return(algeb[0]-'a'+((BOARD_HEIGHT-1)-(algeb[1]-'1'))*BOARD_WIDTH);
	}

	string square_to_algeb(Square sq)
	{
		if(sq==SQUARE_NONE)
		{
			return "-";
		}
		string algeb="";
		algeb+=ALGEB_FILE_OF(FILE_OF_SQUARE(sq));
		algeb+=ALGEB_RANK_OF(RANK_OF_SQUARE(sq));
		return algeb;
	}
	
	void create_sliding_vector(Color color,Piece piece,int i,int j,int rank,int file)
	{	
		rank+=i;
		file+=j;
		MoveDescriptor md;
		int move_table_init_current_ptr_start=move_table_init_current_ptr;
		while(RANK_FILE_OK(rank,file))
		{
			md.to_sq=SQUARE_FROM_RANK_FILE(rank,file);
			md.type=SLIDING_MOVE;
			move_table[move_table_init_current_ptr++]=md;
			rank+=i;
			file+=j;
		}
		for(int move_table_init_current_ptr_i=move_table_init_current_ptr_start;move_table_init_current_ptr_i<move_table_init_current_ptr;move_table_init_current_ptr_i++)
		{
			move_table[move_table_init_current_ptr_i].next_vector=move_table_init_current_ptr;
			#ifdef DEBUG_MOVE_TABLE
			cout << " s " << move_table_init_current_ptr_i << " --> " 
			<< square_to_algeb(move_table[move_table_init_current_ptr_i].to_sq) 
			<< " next " << move_table[move_table_init_current_ptr_i].next_vector << endl;
			#endif
		}
	}
	
	void create_descriptor(Color color,Piece piece,Square square)
	{
	
		int rank=RANK_OF_SQUARE(square);
		int file=FILE_OF_SQUARE(square);
		
		MoveDescriptor md;
		
		#ifdef DEBUG_MOVE_TABLE
		cout << "creating color " << NAME_OF_COLOR(color) << " " 
		<< piece_letters[piece] << " " << square_to_algeb(square)
		<< " at " << move_table_init_current_ptr << endl;
		#endif
		
		move_table_ptr[color][piece][square]=move_table_init_current_ptr;
	
		if(piece & SLIDING_PIECE)
		{
			for(int i=-1;i<=1;i++)
			{
				for(int j=-1;j<=1;j++)
				{
					if(abs(i)+abs(j)>0)
					{
						bool straight_ok=(((i*j)==0)&&(piece & STRAIGHT_PIECE));
						bool diagonal_ok=((abs(i*j)==1)&&(piece & DIAGONAL_PIECE));
						if(straight_ok||diagonal_ok)
						{
							create_sliding_vector(color,piece,i,j,rank,file);
						}
					}
				}
			}
		}
		
		if(piece==KNIGHT)
		{
			for(int i=-2;i<=2;i++)
			{
				for(int j=-2;j<=2;j++)
				{
					if((abs(i*j)==2)&&(RANK_FILE_OK(rank+i,file+j)))
					{
						md.to_sq=SQUARE_FROM_RANK_FILE(rank+i,file+j);
						md.type=SINGLE_MOVE;
						#ifdef DEBUG_MOVE_TABLE
						cout << " n " << move_table_init_current_ptr 
						<< " --> " << (int)md.to_sq << " "
						<< square_to_algeb(md.to_sq) 
						<< endl;
						#endif
						move_table[move_table_init_current_ptr++]=md;
					}
				}
			}
		}
		
		if((piece==KING)||(piece==VOID_PIECE))
		{
		
			// VOID_PIECE has only the normal king moves
		
			for(int i=-1;i<=1;i++)
			{
				for(int j=-1;j<=1;j++)
				{
					if(((abs(i)+abs(j))>0)&&(RANK_FILE_OK(rank+i,file+j)))
					{
						md.to_sq=SQUARE_FROM_RANK_FILE(rank+i,file+j);
						md.type=(SINGLE_MOVE|KING_MOVE);
						#ifdef DEBUG_MOVE_TABLE
						cout << " k " << move_table_init_current_ptr 
						<< " --> " << square_to_algeb(md.to_sq) 
						<< endl;
						#endif
						move_table[move_table_init_current_ptr++]=md;
					}
				}
			}
			
			if(piece==KING)
			{
			
				if((square==CASTLE_FROM_SQUARE_WHITE)||(square==CASTLE_FROM_SQUARE_BLACK))
				{
					for(int f=-2;f<=2;f+=4)
					{
						md.to_sq=SQUARE_FROM_RANK_FILE(rank,file+f);
						md.type=(SINGLE_MOVE|KING_MOVE|CASTLING_MOVE);
						md.type|=(f==-2?CASTLING_QUEEN_SIDE_MOVE:CASTLING_KING_SIDE_MOVE);
						#ifdef DEBUG_MOVE_TABLE
						cout << " c " << move_table_init_current_ptr 
						<< " --> " << square_to_algeb(md.to_sq) 
						<< endl;
						#endif
						move_table[move_table_init_current_ptr++]=md;
					}
				}
				
			}
		}
		
		if(piece==PAWN)
		{
			int dr=(color==WHITE?-1:1);
			int br=BASE_RANK(color);
			int pr=PROMOTION_RANK(color);
			for(int f=-1;f<=1;f++)
			{
				if(RANK_FILE_OK(file+f,rank+dr))
				{
					md.to_sq=SQUARE_FROM_RANK_FILE(rank+dr,file+f);
					md.type=PAWN_MOVE;
					md.type|=(f==0?(PAWN_PUSH_MOVE|PAWN_PUSH_BY_ONE_MOVE):(PAWN_CAPTURE_MOVE|CAPTURE_MOVE));
					#ifdef VARIANT_ATOMIC
					if((f==0)&&(rank==pr))
					{
						MoveType type=md.type|PROMOTION_MOVE;
						for(int pp=0;pp<4;pp++)
						{
							md.type=type|PROMOTION_PIECES[pp];
							#ifdef DEBUG_MOVE_TABLE
							cout << " r " << move_table_init_current_ptr 
							<< " pp " << pp
							<< " --> " << square_to_algeb(md.to_sq) 
							<< " type " << md.type
							<< " prom piece " << INFO_OF_TYPE(md.type)
							<< endl;
							#endif
							move_table[move_table_init_current_ptr++]=md;						
						}
					}
					else
					{
						#ifdef DEBUG_MOVE_TABLE
						cout << " p " << move_table_init_current_ptr 
						<< " --> " << square_to_algeb(md.to_sq) 
						<< " type " << md.type
						<< endl;
						#endif
						if(md.type & PAWN_CAPTURE_MOVE)
						{
							md.type|=SQUARE_FROM_RANK_FILE(rank,file+f);
						}
						move_table[move_table_init_current_ptr++]=md;
					}
					#else
					if(rank==pr)
					{
						MoveType type=md.type|PROMOTION_MOVE;
						for(int pp=0;pp<4;pp++)
						{
							md.type=type|PROMOTION_PIECES[pp];
							#ifdef DEBUG_MOVE_TABLE
							cout << " r " << move_table_init_current_ptr 
							<< " pp " << pp
							<< " --> " << square_to_algeb(md.to_sq) 
							<< " type " << md.type
							<< " prom piece " << INFO_OF_TYPE(md.type)
							<< endl;
							#endif
							move_table[move_table_init_current_ptr++]=md;						
						}
					}
					else
					{
						#ifdef DEBUG_MOVE_TABLE
						cout << " p " << move_table_init_current_ptr 
						<< " --> " << square_to_algeb(md.to_sq) 
						<< " type " << md.type
						<< endl;
						#endif
						if(md.type & PAWN_CAPTURE_MOVE)
						{
							md.type|=SQUARE_FROM_RANK_FILE(rank,file+f);
						}
						move_table[move_table_init_current_ptr++]=md;
					}
					#endif
				}
			}
			
			if((RANK_FILE_OK(rank+2*dr,file))&&(rank==br))
			{
				md.to_sq=SQUARE_FROM_RANK_FILE(rank+2*dr,file);
				md.type=PAWN_MOVE|PAWN_PUSH_MOVE|PAWN_PUSH_BY_TWO_MOVE;
				Square ep_sq=SQUARE_FROM_RANK_FILE(rank+dr,file);
				md.type|=ep_sq;
				#ifdef DEBUG_MOVE_TABLE
				cout << " t " << move_table_init_current_ptr 
				<< " --> " << square_to_algeb(md.to_sq) 
				<< " type " << md.type
				<< endl;
				#endif
				move_table[move_table_init_current_ptr++]=md;
			}
		}
		
		#ifdef DEBUG_MOVE_TABLE
		cout << "end piece at " << move_table_init_current_ptr << endl;
		#endif
		
		md.to_sq=SQUARE_NONE;
		md.type=END_PIECE;
		move_table[move_table_init_current_ptr++]=md;
		
	}
	
	void init_move_table()
	{
	
		memset(move_table,0,sizeof(move_table));
	
		move_table_init_current_ptr=0;
		
		for(Color color=0;color<=1;color++)
		{
			for(Piece piece=0;piece<NUM_PIECES;piece++)
			{
				for(Square square=0;square<BOARD_SIZE;square++)
				{
					create_descriptor(color,piece,square);
				}
			}
		}
		
		#ifdef DEBUG_MOVE_TABLE
		cout << "total " << move_table_init_current_ptr 
		<< " of " << MOVE_TABLE_SIZE 
		<< " ( " << sizeof(move_table) << " ) "
		<< endl;
		#endif
		
	}

	void init()
	{
		init_move_table();
		init_material_values();
	}
	
	#ifdef VARIANT_ATOMIC
	void Position::make_move_raw(Move m)
	{
	
		ep_square=SQUARE_NONE;
	
		Square from_sq=m.from_sq;
		Square to_sq=m.to_sq;
		Piece from_piece=board[from_sq];
		Piece to_piece=board[to_sq];
		MoveType type=m.type;
		
		board[from_sq]=NO_PIECE;
		
		if(to_piece)
		{
		
			// capture
		
			board[to_sq]=NO_PIECE;
			
			int current_ptr=move_table_ptr[0][VOID_PIECE][to_sq];
			
			while(move_table[current_ptr].type)
			{
				Square exp_sq=move_table[current_ptr].to_sq;
				
				if(PIECE_OF(board[exp_sq])!=PAWN)
				{
					board[exp_sq]=NO_PIECE;
				}
				
				current_ptr++;
			}
			
		}
		else
		{
		
			if(type & EP_CAPTURE_MOVE)
			{
				board[m.to_sq]=NO_PIECE;
				board[INFO_OF_TYPE(type)]=NO_PIECE;
			}
			else
			{
				board[m.to_sq]=from_piece;
			}
			
		}
		
		//////////////////////////////////////////////////////////////////////////////
		// if any corner square becomes empty delete the corresponding castling right
		
		if(!board[CASTLING_RIGHT_DISABLE_SQUARE_K])
		{
			castling_rights&=~CASTLING_RIGHT_K;
		}
		
		if(!board[CASTLING_RIGHT_DISABLE_SQUARE_Q])
		{
			castling_rights&=~CASTLING_RIGHT_Q;
		}
		
		if(!board[CASTLING_RIGHT_DISABLE_SQUARE_k])
		{
			castling_rights&=~CASTLING_RIGHT_k;
		}
		
		if(!board[CASTLING_RIGHT_DISABLE_SQUARE_q])
		{
			castling_rights&=~CASTLING_RIGHT_q;
		}
		
		//////////////////////////////////////////////////////////////////////////////
		
		//////////////////////////////////////////////////////////////////////////////
		// special moves
		
		if(PIECE_OF(from_piece)==KING)
		{
			king_pos[TURN_OF(from_piece)]=to_sq;
			castling_rights&=~(COLOR_OF(from_piece)==WHITE?CASTLING_RIGHT_W:CASTLING_RIGHT_b);
		}
		
		if(type & SPECIAL_MOVE)
		{
		
			if(type & PAWN_PUSH_BY_TWO_MOVE)
			{
				ep_square=INFO_OF_TYPE(type);
			}
			
			if(type & PROMOTION_MOVE)
			{
				board[m.to_sq]=PIECE_COLOR_OF_COLOR(turn)|INFO_OF_TYPE(m.type);
			}
			
			if(type & CASTLING_MOVE)
			{
			
				if(turn==WHITE)
				{
					if(type & CASTLING_KING_SIDE_MOVE)
					{
						board[CASTLING_RIGHT_DISABLE_SQUARE_K]=NO_PIECE;
						board[CASTLE_FROM_SQUARE_WHITE+1]=WHITE_PIECE|ROOK;
					}
					
					if(type & CASTLING_QUEEN_SIDE_MOVE)
					{
						board[CASTLING_RIGHT_DISABLE_SQUARE_Q]=NO_PIECE;
						board[CASTLE_FROM_SQUARE_WHITE-1]=WHITE_PIECE|ROOK;
					}
					
				}
				else //if(turn==BLACK)
				{
					if(type & CASTLING_KING_SIDE_MOVE)
					{
						board[CASTLING_RIGHT_DISABLE_SQUARE_k]=NO_PIECE;
						board[CASTLE_FROM_SQUARE_BLACK+1]=BLACK_PIECE|ROOK;
					}
					
					if(type & CASTLING_QUEEN_SIDE_MOVE)
					{
						board[CASTLING_RIGHT_DISABLE_SQUARE_q]=NO_PIECE;
						board[CASTLE_FROM_SQUARE_BLACK-1]=BLACK_PIECE|ROOK;
					}
					
				}
				
			}
			
		}
		
		//////////////////////////////////////////////////////////////////////////////
		
		turn=OPPOSITE_TURN(turn);
		
		//init_move_generator();
		
	}
	#else
	void Position::make_move_raw(Move m)
	{
	
		ep_square=SQUARE_NONE;
	
		Square from_sq=m.from_sq;
		Square to_sq=m.to_sq;
		Piece from_piece=board[from_sq];
		Piece to_piece=board[to_sq];
		MoveType type=m.type;
		
		board[from_sq]=NO_PIECE;
		board[m.to_sq]=from_piece;
		
		if(type & EP_CAPTURE_MOVE)
		{
			board[INFO_OF_TYPE(type)]=NO_PIECE;
		}
		
		//////////////////////////////////////////////////////////////////////////////
		// if any corner square becomes empty delete the corresponding castling right
		
		if(!board[CASTLING_RIGHT_DISABLE_SQUARE_K])
		{
			castling_rights&=~CASTLING_RIGHT_K;
		}
		
		if(!board[CASTLING_RIGHT_DISABLE_SQUARE_Q])
		{
			castling_rights&=~CASTLING_RIGHT_Q;
		}
		
		if(!board[CASTLING_RIGHT_DISABLE_SQUARE_k])
		{
			castling_rights&=~CASTLING_RIGHT_k;
		}
		
		if(!board[CASTLING_RIGHT_DISABLE_SQUARE_q])
		{
			castling_rights&=~CASTLING_RIGHT_q;
		}
		
		//////////////////////////////////////////////////////////////////////////////
		
		//////////////////////////////////////////////////////////////////////////////
		// special moves
		
		if(PIECE_OF(from_piece)==KING)
		{
			king_pos[TURN_OF(from_piece)]=to_sq;
			castling_rights&=~(COLOR_OF(from_piece)==WHITE?CASTLING_RIGHT_W:CASTLING_RIGHT_b);
		}
		
		if(type & SPECIAL_MOVE)
		{
		
			if(type & PAWN_PUSH_BY_TWO_MOVE)
			{
				ep_square=INFO_OF_TYPE(type);
			}
			
			if(type & PROMOTION_MOVE)
			{
				board[m.to_sq]=PIECE_COLOR_OF_COLOR(turn)|INFO_OF_TYPE(m.type);
			}
			
			if(type & CASTLING_MOVE)
			{
			
				if(turn==WHITE)
				{
					if(type & CASTLING_KING_SIDE_MOVE)
					{
						board[CASTLING_RIGHT_DISABLE_SQUARE_K]=NO_PIECE;
						board[CASTLE_FROM_SQUARE_WHITE+1]=WHITE_PIECE|ROOK;
					}
					
					if(type & CASTLING_QUEEN_SIDE_MOVE)
					{
						board[CASTLING_RIGHT_DISABLE_SQUARE_Q]=NO_PIECE;
						board[CASTLE_FROM_SQUARE_WHITE-1]=WHITE_PIECE|ROOK;
					}
					
				}
				else //if(turn==BLACK)
				{
					if(type & CASTLING_KING_SIDE_MOVE)
					{
						board[CASTLING_RIGHT_DISABLE_SQUARE_k]=NO_PIECE;
						board[CASTLE_FROM_SQUARE_BLACK+1]=BLACK_PIECE|ROOK;
					}
					
					if(type & CASTLING_QUEEN_SIDE_MOVE)
					{
						board[CASTLING_RIGHT_DISABLE_SQUARE_q]=NO_PIECE;
						board[CASTLE_FROM_SQUARE_BLACK-1]=BLACK_PIECE|ROOK;
					}
					
				}
				
			}
			
		}
		
		//////////////////////////////////////////////////////////////////////////////
		
		turn=OPPOSITE_TURN(turn);
		
		//init_move_generator();
		
	}
	#endif
	
	void Position::make_move(Move m)
	{
		make_move_raw(m);
		if(turn==WHITE)
		{
			fullmove_number++;
		}
		if(m.type & (PAWN_MOVE|CAPTURE_MOVE))
		{
			halfmove_clock=0;
		}
		else
		{
			halfmove_clock++;
		}
	}
	
	void Position::reset()
	{
		set_from_fen((const char*)"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
	}

	void Position::set_from_fen(const char* fen)
	{
	
		Square sq=0;
		char f;

		memset(board,NO_PIECE,BOARD_SIZE);

		king_pos[WHITE]=63;
		king_pos[BLACK]=0;

		// defaults

		turn=WHITE;
		castling_rights=CASTLING_RIGHT_NONE;
		ep_square=SQUARE_NONE;

		halfmove_clock=0;
		fullmove_number=1;

		do
		{
			f=*fen++;
			if((f>='1')&&(f<='9'))
			{
				f-='0';
				while(f--)
				{
					board[sq++]=NO_PIECE;
				}
			}
			else
			{
				switch(f)
				{
					case 'N': board[sq++]=WHITE_PIECE|KNIGHT;break;
					case 'n': board[sq++]=BLACK_PIECE|KNIGHT;break;
					case 'B': board[sq++]=WHITE_PIECE|BISHOP;break;
					case 'b': board[sq++]=BLACK_PIECE|BISHOP;break;
					case 'R': board[sq++]=WHITE_PIECE|ROOK;break;
					case 'r': board[sq++]=BLACK_PIECE|ROOK;break;
					case 'Q': board[sq++]=WHITE_PIECE|QUEEN;break;
					case 'q': board[sq++]=BLACK_PIECE|QUEEN;break;
					case 'K':
							{
								board[sq]=WHITE_PIECE|KING;
								king_pos[WHITE]=sq++;
								break;
							}
					case 'k':
							{
								board[sq]=BLACK_PIECE|KING;
								king_pos[BLACK]=sq++;
								break;
							}
					case 'P': board[sq++]=WHITE_PIECE|PAWN;break;
					case 'p': board[sq++]=BLACK_PIECE|PAWN;break;
				}
			}
		}while(f&&(f!=' ')&&(sq<BOARD_SIZE));

		while(f&&(f!=' ')){f=*fen++;};

		if(f!=' ')
		{
			// invalid fen, use defaults
			init_move_generator();
			return;
		}

		f=*fen++;

		turn=f=='w'?WHITE:BLACK;

		f=*fen++;

		if(f!=' ')
		{
			// invalid fen, use defaults
			init_move_generator();
			return;
		}

		f=*fen++;

		while(f&&(f!=' '))
		{
			switch(f)
			{
				case 'K': castling_rights|=CASTLING_RIGHT_K;break;
				case 'Q': castling_rights|=CASTLING_RIGHT_Q;break;
				case 'k': castling_rights|=CASTLING_RIGHT_k;break;
				case 'q': castling_rights|=CASTLING_RIGHT_q;break;
			}
			f=*fen++;
		}

		if(f!=' ')
		{
			// invalid fen, use defaults
			init_move_generator();
			return;
		}

		f=*fen;

		if(f!='-')
		{
			ep_square=algeb_to_square(fen);
		}
		
		while(f&&(f!=' ')){f=*fen++;};
		
		if(f==' ')
		{
		
			string rest=fen;
			istringstream ins;
			ins.str(rest);
			
			ins >> halfmove_clock >> fullmove_number;
			
		}
		
		init_move_generator();

	}
	
	void Position::print_king_status(Color color)
	{
		cout << (color==WHITE?"wk":"bk") << "@" << square_to_algeb(king_pos[color]) << " "
		<< (is_in_check(color)?"+":" ")
		<< (is_exploded(color)?"*":" ")
		<< " checkers " << attackers_on_square_of_color(king_pos[color],OPPOSITE_COLOR(color),COUNT_ALL)
		<< " attackers " << attackers_on_king_of_color(color);
	}

	void Position::print_board()
	{
	
		string sep="   ";
	
		for(Rank rank=0;rank<=BOARD_LAST_RANK_INDEX;rank++)
		{
		
			cout << (char)(ALGEB_RANK_OF(rank)) << "  ";
			
			for(Rank file=0;file<=BOARD_LAST_FILE_INDEX;file++)
			{
				Piece piece=board[SQUARE_FROM_RANK_FILE(rank,file)];
				cout << piece_letters[piece];
			}
			
			if(rank==0)
			{
				cout << sep << "turn [ " << NAME_OF_TURN(turn)
				<< " ] , halfmove clock [ " << halfmove_clock
				<< " ] , fullmove number [ " << fullmove_number << " ]";
			}
			
			if(rank==1)
			{
				cout << sep << "ep square [ " << square_to_algeb(ep_square) << " ]";
			}
			
			if(rank==2)
			{
				cout << sep << "castling rights [ "
					<< (castling_rights&CASTLING_RIGHT_K?"K":"")
					<< (castling_rights&CASTLING_RIGHT_Q?"Q":"")
					<< (castling_rights&CASTLING_RIGHT_k?"k":"")
					<< (castling_rights&CASTLING_RIGHT_q?"q":"")
					<< (castling_rights==CASTLING_RIGHT_NONE?"-":"")
					<< " ]";;
			}
			
			if(rank==3)
			{
				cout << sep;
				print_king_status(WHITE);
			}
			
			if(rank==4)
			{
				cout << sep;
				print_king_status(BLACK);
			}
			
			if(rank==5)
			{
				cout << sep
				<< "mob w " << count_pseudo_legal_moves(WHITE)
				<< " mat w " << count_material_of_color(WHITE);
			}
			
			if(rank==6)
			{
				cout << sep
				<< "mob b " << count_pseudo_legal_moves(BLACK)
				<< " mat b " << count_material_of_color(BLACK);
			}
			
			if(rank==7)
			{
			
				cout << sep;
				cout << (adjacent_kings()?"adjacent kings, ":"");
			
				int no_legal_moves=count_legal_moves(turn);
				
				cout << "legal moves " << no_legal_moves << " ";
				
				if(no_legal_moves==0)
				{
					if(is_in_check(turn))
					{
						cout << "mate";
					}
					else
					{
						cout << "stalemate";
					}
				}
			}
			
			cout << endl;
			
		}
		
		cout << endl << "   abcdefgh"
		<< sep
		<< "matb " << count_material_balance_for_color(turn)
		;
		cout << " ecorr " << count_endgame_corr_for_color(turn)
		<< " heu rel " << relative_heuristic_value();
		
		cout << endl;
		
	}
	
	#ifdef VARIANT_ATOMIC
	int Position::attackers_on_square_of_color(Square sq,Color color,bool find_first)
	{
	
		int num_attackers=0;
		
		for(int i=0;i<NUM_CHECKING_PIECES;i++)
		{
		
			Piece test_piece=PIECE_COLOR_OF_COLOR(color)|CHECKING_PIECES[i];
			
			bool is_sliding=((test_piece & SLIDING_PIECE)!=0);
			
			int current_ptr=move_table_ptr[OPPOSITE_COLOR(color)][CHECKING_PIECES[i]][sq];
			
			while(move_table[current_ptr].type)
			{
			
				Piece to_piece=board[move_table[current_ptr].to_sq];
			
				if(to_piece)
				{
					if(to_piece==test_piece)
					{
						if(!(move_table[current_ptr].type & PAWN_PUSH_MOVE))
						{
							if(find_first)
							{
								return 1;
							}
							else
							{
								num_attackers++;
								if(is_sliding)
								{
									current_ptr=move_table[current_ptr].next_vector;
								}
								else
								{
									current_ptr++;
								}
							}
						}
						else
						{
							current_ptr++;
						}
					}
					else
					{
						if(is_sliding)
						{
							current_ptr=move_table[current_ptr].next_vector;
						}
						else
						{
							current_ptr++;
						}
					}
				}
				else
				{
					current_ptr++;
				}
			}
			
		}
		
		return num_attackers;
		
	}
	#else
	int Position::attackers_on_square_of_color(Square sq,Color color,bool find_first)
	{
	
		int num_attackers=0;
		
		for(int i=0;i<NUM_CHECKING_PIECES;i++)
		{
		
			Piece test_piece=PIECE_COLOR_OF_COLOR(color)|CHECKING_PIECES[i];
			
			bool is_sliding=((test_piece & SLIDING_PIECE)!=0);
			
			int current_ptr=move_table_ptr[OPPOSITE_COLOR(color)]
				[
					CHECKING_PIECES[i]!=KING ? CHECKING_PIECES[i] : VOID_PIECE
				]
				[sq];
			
			while(move_table[current_ptr].type)
			{
			
				Piece to_piece=board[move_table[current_ptr].to_sq];
			
				if(to_piece)
				{
					if(to_piece==test_piece)
					{
						if(!(move_table[current_ptr].type & PAWN_PUSH_MOVE))
						{
							if(find_first)
							{
								return 1;
							}
							else
							{
								num_attackers++;
								if(is_sliding)
								{
									current_ptr=move_table[current_ptr].next_vector;
								}
								else
								{
									current_ptr++;
								}
							}
						}
						else
						{
							current_ptr++;
						}
					}
					else
					{
						if(is_sliding)
						{
							current_ptr=move_table[current_ptr].next_vector;
						}
						else
						{
							current_ptr++;
						}
					}
				}
				else
				{
					current_ptr++;
				}
			}
			
		}
		
		return num_attackers;
		
	}
	#endif
	
	int Position::attackers_on_king_of_color(Color color)
	{
		Square sq=king_pos[color];
		
		int current_ptr=move_table_ptr[0][VOID_PIECE][sq];
		
		int num_attackers=0;
		
		while(move_table[current_ptr].type)
		{
			Square to_sq;
			
			to_sq=move_table[current_ptr].to_sq;
			num_attackers+=attackers_on_square_of_color(to_sq,OPPOSITE_COLOR(color),COUNT_ALL);
			
			current_ptr++;
		}
		
		return num_attackers;
	}
	
	bool Position::is_exploded(Color color)
	{
	
		Piece piece_at_king_pos=board[king_pos[color]];
		
		Piece should_be=PIECE_COLOR_OF_COLOR(color)|KING;
		
		return (piece_at_king_pos!=should_be);
		
	}
	
	bool Position::adjacent_kings()
	{
	
		Square sq_white=king_pos[WHITE];
		
		if(board[sq_white]!=(WHITE_PIECE|KING))
		{
			return false;
		}
		
		int current_ptr=move_table_ptr[0][VOID_PIECE][sq_white];
		
		while(move_table[current_ptr].type)
		{
			MoveDescriptor md=move_table[current_ptr];
			
			if(board[md.to_sq]==(BLACK_PIECE|KING))
			{
				return true;
			}
			
			current_ptr++;
		}
		
		return false;
		
	}
	
	#ifdef VARIANT_ATOMIC
	bool Position::is_in_check(Color color)
	{
		
		if(adjacent_kings())
		{
			return false;
		}
	
		if(is_exploded(color))
		{
			return true;
		}
		
		return (attackers_on_square_of_color(king_pos[color],OPPOSITE_COLOR(color),FIND_FIRST)>0);
		
	}
	#else
	bool Position::is_in_check(Color color)
	{
		
		return (attackers_on_square_of_color(king_pos[color],OPPOSITE_COLOR(color),FIND_FIRST)>0);
		
	}
	#endif
	
	void Position::init_move_generator()
	{
	
		current_move_gen_sq=0;
		next_move_gen_sq();
		
		is_search_move=false;
		
	}
	
	void Position::next_move_gen_sq()
	{
	
		while(
			(current_move_gen_sq<BOARD_SIZE)
			&&
			(
				(!board[current_move_gen_sq])
				||
				(COLOR_OF(board[current_move_gen_sq])!=turn)
			)
		)
		{
			current_move_gen_sq++;
		}
		if(current_move_gen_sq<BOARD_SIZE)
		{
			current_piece=board[current_move_gen_sq];
			current_move_gen_ptr=move_table_ptr[COLOR_OF(current_piece)][PIECE_OF(current_piece)][current_move_gen_sq];
		}
		
	}
	
	bool Position::next_pseudo_legal_move()
	{
	
		while(current_move_gen_sq<BOARD_SIZE)
		{
		
			while(move_table[current_move_gen_ptr].type)
			{
			
				MoveDescriptor md=move_table[current_move_gen_ptr];
				Square to_sq=md.to_sq;
				MoveType type=md.type;
				Piece to_piece=board[to_sq];
				
				if(!to_piece)
				{
				
					if(type & PAWN_PUSH_BY_TWO_MOVE)
					{
						Square passing_square=INFO_OF_TYPE(type);
						
						if(board[passing_square])
						{
							current_move_gen_ptr++;
						}
						else
						{
							try_move.from_sq=current_move_gen_sq;
							try_move.to_sq=to_sq;
							try_move.type=type;
							current_move_gen_ptr++;
							return true;
						}
					}
					else if(!(type & PAWN_CAPTURE_MOVE))
					{
						try_move.from_sq=current_move_gen_sq;
						try_move.to_sq=to_sq;
						try_move.type=type;
						current_move_gen_ptr++;
						return true;
					}
					else
					{
						if(ep_square==to_sq)
						{
							try_move.from_sq=current_move_gen_sq;
							try_move.to_sq=to_sq;
							try_move.type=type|EP_CAPTURE_MOVE;
							current_move_gen_ptr++;
							return true;
						}
						else
						{
							current_move_gen_ptr++;
						}
					}
					
				}
				else if(COLOR_OF(to_piece)==turn)
				{
				
					if(type & SLIDING_MOVE)
					{
						current_move_gen_ptr=md.next_vector;
					}
					else
					{
						current_move_gen_ptr++;
					}
					
				}
				else
				{
				
					if(type & SLIDING_MOVE)
					{
						current_move_gen_ptr=md.next_vector;
					}
					else
					{
						current_move_gen_ptr++;
					}
					
					if(!(type & PAWN_PUSH_MOVE))
					{
						try_move.from_sq=current_move_gen_sq;
						try_move.to_sq=to_sq;
						try_move.type=type|CAPTURE_MOVE;
						return true;
					}
					
				}
				
			}
			
			current_move_gen_sq++;
			next_move_gen_sq();
			
		}
		
		return false;
	}

	#ifdef VARIANT_ATOMIC
	bool Position::next_legal_move()
	{
	
		if((is_search_move)&&(!search_move_done))
		{
			try_move=search_move;
			search_move_done=true;
			return true;
		}
	
		while(next_pseudo_legal_move())
		{
		
			if((is_search_move)&&(try_move.equal_to(search_move)))
			{
				continue;
			}
		
			Position dummy=*this;
			
			if(try_move.type & CASTLING_MOVE)
			{
			
				if(turn==WHITE)
				{
					if(try_move.type & CASTLING_KING_SIDE_MOVE)
					{
						if(!(castling_rights & CASTLING_RIGHT_K)){continue;}
						if(is_in_check_square(60,WHITE)){continue;}
						if(is_in_check_square(61,WHITE)){continue;}
						if(board[61]){continue;}
						if(board[62]){continue;}
					}
					
					if(try_move.type & CASTLING_QUEEN_SIDE_MOVE)
					{
						if(!(castling_rights & CASTLING_RIGHT_Q)){continue;}
						if(is_in_check_square(60,WHITE)){continue;}
						if(is_in_check_square(59,WHITE)){continue;}
						if(board[59]){continue;}
						if(board[58]){continue;}
						if(board[57]){continue;}
					}
				}
				
				if(turn==BLACK)
				{
					if(try_move.type & CASTLING_KING_SIDE_MOVE)
					{
						if(!(castling_rights & CASTLING_RIGHT_k)){continue;}
						if(is_in_check_square(4,BLACK)){continue;}
						if(is_in_check_square(5,BLACK)){continue;}
						if(board[5]){continue;}
						if(board[6]){continue;}
					}
					
					if(try_move.type & CASTLING_QUEEN_SIDE_MOVE)
					{
						if(!(castling_rights & CASTLING_RIGHT_q)){continue;}
						if(is_in_check_square(4,BLACK)){continue;}
						if(is_in_check_square(3,BLACK)){continue;}
						if(board[3]){continue;}
						if(board[2]){continue;}
						if(board[1]){continue;}
					}
				}
			
			}
			
			dummy.make_move(try_move);
			
			if(
				(!dummy.is_in_check(turn))
				||
				(
					(dummy.is_exploded(dummy.turn))
					&&
					(!(dummy.is_exploded(turn)))
				)
			)
			{
			
				return true;

			}
			
		}
		
		return false;
	}
	#else
	bool Position::next_legal_move()
	{
	
		if((is_search_move)&&(!search_move_done))
		{
			try_move=search_move;
			search_move_done=true;
			return true;
		}
	
		while(next_pseudo_legal_move())
		{
		
			if((is_search_move)&&(try_move.equal_to(search_move)))
			{
				continue;
			}
		
			Position dummy=*this;
			
			if(try_move.type & CASTLING_MOVE)
			{
			
				if(turn==WHITE)
				{
					if(try_move.type & CASTLING_KING_SIDE_MOVE)
					{
						if(!(castling_rights & CASTLING_RIGHT_K)){continue;}
						if(is_in_check_square(60,WHITE)){continue;}
						if(is_in_check_square(61,WHITE)){continue;}
						if(board[61]){continue;}
						if(board[62]){continue;}
					}
					
					if(try_move.type & CASTLING_QUEEN_SIDE_MOVE)
					{
						if(!(castling_rights & CASTLING_RIGHT_Q)){continue;}
						if(is_in_check_square(60,WHITE)){continue;}
						if(is_in_check_square(59,WHITE)){continue;}
						if(board[59]){continue;}
						if(board[58]){continue;}
						if(board[57]){continue;}
					}
				}
				
				if(turn==BLACK)
				{
					if(try_move.type & CASTLING_KING_SIDE_MOVE)
					{
						if(!(castling_rights & CASTLING_RIGHT_k)){continue;}
						if(is_in_check_square(4,BLACK)){continue;}
						if(is_in_check_square(5,BLACK)){continue;}
						if(board[5]){continue;}
						if(board[6]){continue;}
					}
					
					if(try_move.type & CASTLING_QUEEN_SIDE_MOVE)
					{
						if(!(castling_rights & CASTLING_RIGHT_q)){continue;}
						if(is_in_check_square(4,BLACK)){continue;}
						if(is_in_check_square(3,BLACK)){continue;}
						if(board[3]){continue;}
						if(board[2]){continue;}
						if(board[1]){continue;}
					}
				}
			
			}
			
			dummy.make_move(try_move);
			
			if(
				(!dummy.is_in_check(turn))
			)
			{
			
				return true;

			}
			
		}
		
		return false;
	}
	#endif
	
	char algeb_puff[6];
	const char* Move::algeb()
	{
		string algeb="";
		algeb+=square_to_algeb(from_sq);
		algeb+=square_to_algeb(to_sq);
		if(type & PROMOTION_MOVE)
		{
			algeb+=piece_letters[INFO_OF_TYPE(type)];
		}
		strcpy(algeb_puff,algeb.c_str());
		return algeb_puff;
	}
	
	bool Move::equal_to(Move m)
	{
		return (
			(from_sq==m.from_sq)
			&&
			(to_sq==m.to_sq)
			&&
			(type==m.type)
			);
	}
	
	bool Position::is_algeb_move_legal(const char* algeb)
	{
	
		Position dummy=*this;
		
		dummy.init_move_generator();
		
		while(dummy.next_legal_move())
		{
			if(0==strcmp(algeb,dummy.try_move.algeb()))
			{
				try_move=dummy.try_move;
				return true;
			}
		}
		
		return false;
		
	}
	
	bool Position::is_san_move_legal(const char* san)
	{
	
		Position dummy=*this;
		
		dummy.init_move_generator();
		
		while(dummy.next_legal_move())
		{
			if(0==strcmp(san,dummy.to_san(dummy.try_move)))
			{
				try_move=dummy.try_move;
				return true;
			}
		}
		
		return false;
		
	}
	
	int Position::count_pseudo_legal_moves(Color color)
	{
	
		Position dummy=*this;
		
		dummy.turn=color;
		
		dummy.init_move_generator();
		
		int count=0;
		while(dummy.next_pseudo_legal_move())
		{
			count++;
		}
		
		return count;
		
	}
	
	int Position::count_legal_moves(Color color)
	{
	
		Position dummy=*this;
		
		dummy.turn=color;
		
		dummy.init_move_generator();
		
		int count=0;
		while(dummy.next_legal_move())
		{
			count++;
		}
		
		return count;
		
	}

	int Position::count_material_of_color(Color color)
	{
	
		int material=0;
		
		for(Square sq=0;sq<BOARD_SIZE;sq++)
		{
			Piece piece=board[sq];
			
			if(piece && (COLOR_OF(piece)==color))
			{
				int piece_material_value=material_values[PIECE_OF(piece)];
				material+=piece_material_value;
			}
		}
		
		return abs(material);
		
	}
	
	int Position::count_material_balance_for_color(Color color)
	{
	
		int material=0;
		
		abs_mat=0;
		
		for(Square sq=0;sq<BOARD_SIZE;sq++)
		{
		
			int mat_value=material_values[board[sq]];
		
			material+=mat_value;
			
			abs_mat+=abs(mat_value);
		}
		
		return turn==WHITE?material:-material;
		
	}
	
	int Position::count_endgame_corr_for_color(Color color)
	{
		if(abs_mat>6000)
		{
			return 0;
		}
		
		bool semi_endgame=(abs_mat>4000);
		
		int corr=0;
		
		for(Square sq=0;sq<BOARD_SIZE;sq++)
		{
		
			Piece piece=board[sq];
			
			if(semi_endgame)
			{
				if(PIECE_OF(piece)==QUEEN)
				{
					corr+=material_values[piece]/5;
				}
			}
			else
			{
				if(PIECE_OF(piece)==PAWN)
				{
					corr+=3*material_values[piece]/4;
				}
				
				if(PIECE_OF(piece)==QUEEN)
				{
					corr+=material_values[piece]/4;
				}
			}
			
		}
		
		return turn==WHITE?corr:-corr;
		
	}
	
	int Position::heuristic_value_of(Color color)
	{	
	
		return
		(
		
			count_material_of_color(color)
			+
			count_pseudo_legal_moves(color)*MOBILITY_BONUS
			-
			attackers_on_king_of_color(color)*ATTACKER_BONUS
			+
			rand()%RANDOM_BONUS
			
		);
		
	}
	
	int Position::heuristic_value_non_material_of(Color color)
	{	
	
		return
		(
		
			count_pseudo_legal_moves(color)*MOBILITY_BONUS
			-
			attackers_on_king_of_color(color)*ATTACKER_BONUS
			+
			rand()%RANDOM_BONUS
			
		);
		
	}
	
	int Position::relative_heuristic_value()
	{
	
		int value=
		
			heuristic_value_non_material_of(turn)
			-
			heuristic_value_non_material_of(OPPOSITE_TURN(turn))
			+
			count_material_balance_for_color(turn);
	
		return
		(
		
			value+count_endgame_corr_for_color(turn)
			
		);
		
	}
	
	bool Position::is_in_check_square(Square sq,Color color)
	{
	
		Position dummy=*this;
		
		Piece dummy_king=PIECE_COLOR_OF_COLOR(color)|KING;
		
		dummy.king_pos[color]=sq;
		dummy.board[sq]=dummy_king;
		
		return dummy.is_in_check(color);
		
	}
	
	void Position::set_search_move(Move set_search_move)
	{
	
		search_move=set_search_move;
		
		is_search_move=true;
		
		search_move_done=false;
		
	}
	
	void Position::save()
	{
	
		ofstream o("pos.dat",ios::binary);
		o.write((char*)this,sizeof(Position));
		o.close();
		
	}
	
	void Position::load()
	{
	
		ifstream i("pos.dat",ios::binary);
		if(i.is_open())
		{
			i.read((char*)this,sizeof(Position));
			i.close();
		}
		
	}
	
	PosHashKey Position::calc_key()
	{
	
		key=XXH32((char*)this,sizeof(PositionTrunk),0);
		return key;
		
	}
	
	char to_san_puff[50];
	const char* Position::to_san(Move m)
	{
	
		MoveType type=m.type;
		
		if(type & CASTLING_MOVE)
		{
			if(type & CASTLING_KING_SIDE_MOVE)
			{
				strcpy(to_san_puff,"O-O");
				
			}
			else
			{
				strcpy(to_san_puff,"O-O-O");
			}
			return to_san_puff;
		}
	
		Square from_sq=m.from_sq;
		
		Rank from_rank=RANK_OF_SQUARE(from_sq);
		Rank from_file=FILE_OF_SQUARE(from_sq);
		
		Piece from_piece=board[from_sq];
		Piece from_piece_kind=PIECE_OF(from_piece);
		Piece from_piece_color=COLOR_OF(from_piece);
		
		Square to_sq=m.to_sq;
		
		Rank to_rank=RANK_OF_SQUARE(to_sq);
		Rank to_file=FILE_OF_SQUARE(to_sq);
		
		int current_ptr=move_table_ptr[from_piece_color][from_piece_kind][to_sq];
		
		bool rank_unique=true;
		bool file_unique=true;
		
		while(move_table[current_ptr].type)
		{
			MoveDescriptor md=move_table[current_ptr];
			
			Square current_from_sq=md.to_sq;
			Piece current_piece=board[current_from_sq];
			
			if(current_piece)
			{
				if((current_piece==from_piece)&&(current_from_sq!=from_sq))
				{
					Rank current_from_rank=RANK_OF_SQUARE(current_from_sq);
					Rank current_from_file=FILE_OF_SQUARE(current_from_sq);
					
					if(current_from_rank==from_rank){rank_unique=false;}
					if(current_from_file==from_file){file_unique=false;}
				}
				
				if(from_piece & SLIDING_PIECE)
				{
					current_ptr=md.next_vector;
				}
				else
				{
					current_ptr++;
				}
			}
			else
			{
				current_ptr++;
			}
		}
		
		char piece_letter=piece_letters[WHITE_PIECE|from_piece_kind];
		
		char* to_san_ptr=to_san_puff;
		
		if(from_piece_kind!=PAWN)
		{
			*to_san_ptr++=piece_letter;
		
			if(rank_unique && file_unique)
			{
				
			}
			else if(file_unique)
			{
				*to_san_ptr++=ALGEB_FILE_OF(from_file);
			}
			else if(rank_unique)
			{
				*to_san_ptr++=ALGEB_RANK_OF(from_rank);
			}
			else
			{
				*to_san_ptr++=ALGEB_FILE_OF(from_file);
				*to_san_ptr++=ALGEB_RANK_OF(from_rank);
			}
			
		}
		else
		{
			if(type & CAPTURE_MOVE)
			{
				*to_san_ptr++=ALGEB_FILE_OF(from_file);
			}
		}
		
		if(type & CAPTURE_MOVE)
		{
			*to_san_ptr++='x';
		}
		
		*to_san_ptr++=ALGEB_FILE_OF(to_file);
		*to_san_ptr++=ALGEB_RANK_OF(to_rank);
		
		*to_san_ptr=0;
		
		if(type & EP_CAPTURE_MOVE)
		{
			//strcpy(to_san_ptr," e.p.");
		}
		
		if(type & PROMOTION_MOVE)
		{
			*to_san_ptr++='=';
			*to_san_ptr++=piece_letters[WHITE_PIECE|INFO_OF_TYPE(type)];
			*to_san_ptr=0;
		}
		
		Position dummy=*this;
		
		dummy.make_move(m);
		
		dummy.init_move_generator();
		if(dummy.next_legal_move())
		{
			if(dummy.is_in_check(dummy.turn))
			{
				*to_san_ptr++='+';
				*to_san_ptr=0;
			}
		}
		else
		{
			if(dummy.is_in_check(dummy.turn))
			{
				if(!dummy.is_exploded(dummy.turn))
				{
					*to_san_ptr++='#';
					*to_san_ptr=0;
				}
			}
			else
			{
				*to_san_ptr++='=';
				*to_san_ptr=0;
			}
		}
		
		return to_san_puff;
	}
	
	char game_to_line_puff[5000];
	const char* Game::line()
	{
	
		ostringstream oss;
		
		oss << "";
		
		int fullmove_number;
		
		GameItem* ptr=game;
		
		bool init=true;
		
		while((ptr->next!=NULL)&&(ptr!=current))
		{
		
			Position p=ptr->p;
		
			if(init)
			{
			
				fullmove_number=p.fullmove_number;
			
				oss << fullmove_number << ". ";
				
				if(p.turn==BLACK)
				{
					oss << "... ";
				}
				
				init=false;
			}
			else
			{
				if(p.turn==WHITE)
				{
					fullmove_number++;
					oss << fullmove_number << ". ";
				}
			}
			
			p.init_move_generator();
			
			while(p.next_legal_move())
			{
				Position  dummy=p;
				dummy.make_move(p.try_move);
				if(0==memcmp((char*)&dummy,(char*)(&((ptr->next)->p)),sizeof(PositionTrunk)))
				{
					oss << p.to_san(p.try_move) << " ";
					break;
				}
			}
			
			ptr=ptr->next;
			
		}
		
		strcpy(game_to_line_puff,oss.str().c_str());
		
		return game_to_line_puff;
		
	}
	
	void Game::add_position(Position p)
	{
	
		GameItem* entry=new GameItem;
		entry->p=p;
		
		entry->prev=NULL;
		entry->next=NULL;
		
		if(current==NULL)
		{
			game=entry;
		}
		else
		{
			current->next=entry;
			entry->prev=current;
		}
		
		current=entry;
		
	}
	
	void Game::debug()
	{
		GameItem* ptr=game;
		int i=0;
		cout << "game " << game 
		<< " current " << current
		<< endl;
		while(ptr!=NULL)
		{
			cout << "game " << i << " ptr " << ptr 
			<< " prev " << ptr->prev 
			<< " next " << ptr->next 
			<< endl;
			ptr->p.print_board();
			i++;
			ptr=ptr->next;
		}
	}
	
	
	void Game::add_san_move(const char* san)
	{
		Position p=current->p;
		if(p.is_san_move_legal(san))
		{
		
			cout << "adding move: "
			<< p.fullmove_number
			<< (p.turn==WHITE?". ":". ... ")
			<< p.to_san(p.try_move) 
			<< " ( "
			<< p.try_move.algeb()
			<< " ) "
			<< endl;
			p.make_move(p.try_move);
			cout << "resulting fen: " << p.report_fen() << endl;
			add_position(p);
		}
	}
	
	char pgn_puff[5000];
	void Game::set_from_pgn()
	{
		ifstream i("temp.pgn");
		if(i.is_open())
		{
			bool pos_init=false;
			
			while(i.getline(pgn_puff,5000))
			{
		
				if(pgn_puff[0])
				{
					if(pgn_puff[0]=='[')
					{
						string rest=pgn_puff+1;
						istringstream ins;
						ins.str(rest);
			
						string field;
						ins >> field;
						if(field=="FEN")
						{
		
							string raw_fen,turn,castling_rights,ep_square,halfmove_clock,fullmove_number;
							ins >> raw_fen >> turn >> castling_rights >> ep_square >> halfmove_clock >> fullmove_number;
							string fen=raw_fen+" "+turn+" "+castling_rights+" "+ep_square+" "+halfmove_clock+" "+fullmove_number;
							
							cout << pgn_puff << endl;
							
							Position p;
							
							p.set_from_fen(fen.c_str()+1);
							
							init(p);
							
							cout << "initial fen: " << p.report_fen() << endl;
							
							pos_init=true;
						}
					}
					else
					{
					
						if(!pos_init)
						{
							Position p;
							
							p.reset();
							
							init(p);
							
							cout << "initial fen (starting position): " << p.report_fen() << endl;
							
							pos_init=true;
						}
						
						istringstream ins;
						ins.str(pgn_puff);
						
						cout << "pgn moves: " << pgn_puff << endl;
						
						while(!ins.eof())
						{
							string move_number,move_white,move_black;
							ins >> move_number >> move_white >> move_black;
							
							add_san_move(move_white.c_str());
							add_san_move(move_black.c_str());
						}
						
					}
				}
			}
			i.close();
		}

	}
	
	char report_fen_puff[200];
	const char* Position::report_fen()
	{
		char* report_fen_ptr=report_fen_puff;
		for(int i=0;i<8;i++)
		{
			int empty_count=0;
			for(int j=0;j<8;j++)
			{
				Piece piece=board[i*BOARD_WIDTH+j];
				if(!piece)
				{
					empty_count++;
				}
				else
				{
					if(empty_count)
					{
						*report_fen_ptr++='0'+(char)empty_count;
						empty_count=0;
					}
					*report_fen_ptr++=piece_letters[piece];
				}
			}
			if(empty_count)
			{
				*report_fen_ptr++='0'+(char)empty_count;
			}
			if(i<7)
			{
				*report_fen_ptr++='/';
			}
		}
		
		*report_fen_ptr=0;
		
		ostringstream oss;
		
		oss << " " << (turn==WHITE?"w":"b") << " ";
		
		if(castling_rights)
		{
			if(castling_rights&CASTLING_RIGHT_K){oss << "K";}
			if(castling_rights&CASTLING_RIGHT_Q){oss << "Q";}
			if(castling_rights&CASTLING_RIGHT_k){oss << "k";}
			if(castling_rights&CASTLING_RIGHT_q){oss << "q";}
		}
		else
		{
			oss << "-";
		}
		
		oss << " " << square_to_algeb(ep_square) << " " << halfmove_clock << " " << fullmove_number;
		
		strcat(report_fen_puff,oss.str().c_str());
		
		return report_fen_puff;
	}
	
	void Game::list_fens()
	{
		ofstream o("fens.txt");
		if(o.is_open())
		{
			GameItem* pos=game;
			while(pos!=NULL)
			{
				o << pos->p.report_fen() << endl;
				pos=pos->next;
			}
			o.close();
		}
	}

}