#include <iostream>
#include <sstream>
#include <stdio.h>

#include "utils/include/pthread.h"

using namespace std;

#include "utils/include/myhash.h"

#include "position.h"
#include "analyzer.h"

PositionSpace::Position game[200];
int game_ptr;

void init_main()
{
	PositionSpace::init();
	AnalyzerSpace::init();
	game_ptr=-1;
}

char buf[200];
string message="";

int main(int argc,char** argv)
{

	init_main();
	
	Sleep(200);
	
	PositionSpace::Position p;
	
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
			
			if(list_move_values)
			{
				cout << endl;
				AnalyzerSpace::analyzers[AnalyzerSpace::ALPHABETA_ANALYZER].list_move_values(p);
				list_move_values=false;
			}
			
			cout << endl << message << " [ pos " << AnalyzerSpace::num_deep_positions() << " ] > ";
			
			pthread_mutex_unlock(&AnalyzerSpace::display_mutex);
		}
		
		print_prompt=true;
		message="";
	
		cin.getline(buf,200);
		
		cout << endl;
		
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
			game_ptr=-1;
			message="deep hash loaded";
			continue;
		}
		
		if(0==strcmp(buf,"qal"))
		{
			AnalyzerSpace::analyzers[AnalyzerSpace::ALPHABETA_ANALYZER].quit_search_safe();
			message="alphabeta search quitted";
			continue;
		}
		
		if(0==strcmp(buf,"qd"))
		{
			AnalyzerSpace::quit_deep_search_safe();
			message="deep search quitted";
			continue;
		}
		
		if(buf[0]=='d')
		{
			print_prompt=false;
			AnalyzerSpace::deep_search(p);
		}
		
		if(buf[0]=='v')
		{
			AnalyzerSpace::analyzers[AnalyzerSpace::ALPHABETA_ANALYZER].search_move_values_safe(p);
			list_move_values=true;
		}
		
		if(buf[0]=='n')
		{
			AnalyzerSpace::minimax_smart=true;
			AnalyzerSpace::analyzers[AnalyzerSpace::ALPHABETA_ANALYZER].minimax_out(p);
			AnalyzerSpace::minimax_smart=false;
		}
		
		if(buf[0]=='k')
		{
			AnalyzerSpace::analyzers[AnalyzerSpace::ALPHABETA_ANALYZER].add_node(p);
		}
		
		if(buf[0]=='s')
		{
			print_prompt=false;
			AnalyzerSpace::analyzers[AnalyzerSpace::ALPHABETA_ANALYZER].search_grad(p,(buf[1]-'0'));
		}
		
		if(buf[0]=='i')
		{
			print_prompt=false;
			AnalyzerSpace::analyzers[AnalyzerSpace::ALPHABETA_ANALYZER].search_grad(p,20);
		}
	
		if(buf[0]=='m')
		{
		
			if(p.is_algeb_move_legal(buf+1))
			{
				game[++game_ptr]=p;
				p.make_move(p.try_move);
				message="move made ok";
			}
			else
			{
				message="illegal move";
			}
			
		}
		
		/*if(buf[0]=='p')
		{
		
			PositionSpace::Move m;
			m.from_sq=PositionSpace::algeb_to_square(buf+1);
			m.to_sq=PositionSpace::algeb_to_square(buf+3);
			m.type=0;
			game[++game_ptr]=p;
			p.make_move(m);
			message="move made by force ok";
		}*/
		
		if(buf[0]=='f')
		{
			p.set_from_fen(buf+1);
			message="position set from fen";
		}
		
		if(buf[0]=='u')
		{
			if(game_ptr>=0)
			{
				p=game[game_ptr--];
			}
			
			message="move unmade";
		}
		
		if(buf[0]=='r')
		{
		
			p.reset();
			game_ptr=-1;
			
			message="board resetted";
			
		}
		
		if(buf[0]=='l')
		{
			p.init_move_generator();
			int count=0;
			while(p.next_legal_move())
			{
				cout << p.try_move.algeb() << endl;
				count++;
			}
			
			message="number of moves ";
			ostringstream ss;
			ss << count;
			message+=ss.str();
		}
	
	}while(buf[0]!='x');
	
	return 0;

}