#include "setup.h"

#include "anno.h"

#include "utils/include/xxhash.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

bool anno_verbose=false;
bool is_recommended_move;
Move recommended_move;

int anno_alloc_ptr=1;

AnnoPtr anno_hash[ANNO_HASH_SIZE];

AnnoEntry anno_table[ANNO_TABLE_SIZE];

AnnoHashKey calc_anno_hash_key(AnnoTrunk* anno_trunk)
{
	AnnoHashKey anno_hash_key=(AnnoHashKey)XXH32((void*)anno_trunk,sizeof(AnnoTrunk),0);

	anno_hash_key&=ANNO_HASH_MASK;

	return anno_hash_key;
}

void AnnoEntry::init(Position* p,const char* algeb)
{
	next=0;

	memcpy(id.pos_trunk,(char*)p,sizeof(PositionTrunk));
	memset(id.algeb,0,6);
	strcpy(id.algeb,algeb);
}

AnnoEntry* look_up_anno_entry(Position* p,const char* algeb,bool create)
{

	AnnoEntry dummy;

	dummy.init(p,algeb);

	AnnoHashKey key=calc_anno_hash_key(&dummy.id);

	AnnoPtr entry_ptr=anno_hash[key];

	if(entry_ptr==0)
	{

		if(!create)
		{
			return NULL;
		}
		else
		{
			if(anno_alloc_ptr>ANNO_TABLE_LAST_INDEX)
			{
				return NULL;
			}
			else
			{
				anno_hash[key]=anno_alloc_ptr;

				AnnoEntry* entry=&anno_table[anno_alloc_ptr++];

				entry->init(p,algeb);

				return entry;
			}
		}

	}
	else
	{

		AnnoEntry* entry=&anno_table[anno_hash[key]];

		while((entry->next!=0)&&(0!=memcmp(&dummy.id,&entry->id,sizeof(AnnoTrunk))))
		{
			entry=&anno_table[entry->next];
		}

		if(0==memcmp(&dummy.id,&entry->id,sizeof(AnnoTrunk)))
		{
			return entry;
		}
		else
		{

			if(!create)
			{
				return NULL;
			}
			else
			{
				AnnoEntry* new_entry=&anno_table[anno_alloc_ptr];

				new_entry->init(p,algeb);

				entry->next=anno_alloc_ptr++;

				return new_entry;
			}
		}

	}
}

void save_anno_book()
{
	ofstream o("anno.anb",ios::binary);
	if(o.is_open())
	{
		o.write((char*)&anno_alloc_ptr,sizeof(anno_alloc_ptr));
		o.write((char*)&anno_hash,sizeof(anno_hash));
		o.write((char*)&anno_table,sizeof(anno_table));
		o.close();
	}
}

bool save_annotated_move=true;
bool annotate_move(Position* p,const char* algeb,const char* annot)
{

	if(p->is_algeb_move_legal(algeb))
	{

		AnnoEntry* entry=look_up_anno_entry(p,algeb,DO_CREATE);

		if(entry==NULL)
		{
			return false;
		}

		strcpy(entry->annot,annot);

		if(save_annotated_move)
		{
			save_anno_book();
		}

		return true;

	}
	else
	{

		return false;

	}

}

char annot_nice_puff[50];
char* annot_nice(char* annot)
{
	if(0==strcmp(annot,"!!"))
	{
		strcpy(annot_nice_puff,"very strongly recommended move, status: proven");
	}

	if(0==strcmp(annot,"!"))
	{
		strcpy(annot_nice_puff,"strongly recommended move, status: proven");
	}

	if(0==strcmp(annot,"?!"))
	{
		strcpy(annot_nice_puff,"playable move, status: not proven");
	}

	if(0==strcmp(annot,"-"))
	{
		strcpy(annot_nice_puff,"recommended move, status: proven to be stable");
	}

	if(0==strcmp(annot,"!?"))
	{
		strcpy(annot_nice_puff,"recommended move, status: very promising");
	}

	if(0==strcmp(annot,"?"))
	{
		strcpy(annot_nice_puff,"losing move, status: proven");
	}

	if(0==strcmp(annot,"??"))
	{
		strcpy(annot_nice_puff,"gets mated by force, status: proven");
	}

	return annot_nice_puff;
}

int annot_value(char* annot)
{
	if(0==strcmp(annot,"!!")){return 3;}
	if(0==strcmp(annot,"!")){return 2;}
	if(0==strcmp(annot,"!?")){return 1;}
	if(0==strcmp(annot,"-")){return 0;}
	if(0==strcmp(annot,"?!")){return -1;}
	if(0==strcmp(annot,"?")){return -2;}
	if(0==strcmp(annot,"??")){return -3;}
	
	return -3;
}

int cmp_moves(const void* a,const void* b)
{
	char* aa=((AnnoEntry*)a)->annot;
	char* ab=((AnnoEntry*)b)->annot;
	
	return annot_value(ab)-annot_value(aa);
}

void list_annotated_moves(Position* p)
{

	Position dummy=*p;

	dummy.init_move_generator();
	
	AnnoEntry annotated_moves[50];
	int anno_entry_count=0;

	while(dummy.next_legal_move())
	{

		AnnoEntry* entry=look_up_anno_entry(&dummy,(char*)dummy.try_move.algeb(),DONT_CREATE);

		if(entry!=NULL)
		{
			annotated_moves[anno_entry_count]=*entry;
			
			annotated_moves[anno_entry_count].m=dummy.try_move;
			
			anno_entry_count++;
		}

	}
	
	is_recommended_move=false;
	
	if(anno_entry_count>0)
	{
	
		qsort(&annotated_moves,anno_entry_count,sizeof(AnnoEntry),cmp_moves);
		
		if(annot_value(annotated_moves[0].annot)>-2)
		{
			is_recommended_move=true;
			recommended_move=annotated_moves[0].m;
		}
		
		if(anno_verbose)
		{
		
			for(int i=0;i<anno_entry_count;i++)
			{
				if(i==0){cout << endl;}
			
				cout << " * ( " << (i+1) << " ) " 
				<< annotated_moves[i].id.algeb << " " 
				<< annotated_moves[i].annot 
				/*<< " ( " 
				<< annot_nice(annotated_moves[i].annot) 
				<< " ) "*/
				<< endl;
			}
			
		}
		
		if((is_recommended_move)&&(anno_verbose))
		{
			cout << endl << " recommended move: "
			<< recommended_move.algeb() << endl;
		}
	
	}

}

void init_anno()
{

	memset(anno_hash,0,sizeof(anno_hash));
	anno_alloc_ptr=1;
}

void load_anno_book()
{
	ifstream i("anno.anb",ios::binary);
	if(i.is_open())
	{
		i.read((char*)&anno_alloc_ptr,sizeof(anno_alloc_ptr));
		i.read((char*)&anno_hash,sizeof(anno_hash));
		i.read((char*)&anno_table,sizeof(anno_table));
		i.close();

		#ifndef WINBOARD
		cout << "annotation book loaded " << anno_alloc_ptr << " annotated moves " << endl;
		#endif
	}
	else
	{
		set_anno_default();
		
		#ifndef WINBOARD
		cout << "annotation set to default" << endl;
		#endif
	}
}