#ifndef MYHASH_H
#define MYHASH_H

#include "../../setup.h"

#include <string.h>

#include "xxhash.h"
#include "pthread.h"

#ifdef MY_GNU
#include <sys/time.h>
#else
//#ifdef MY_MSVC
#include <time.h>
#endif

namespace MyHashSpace {

//#define MYHASH_DEBUG

#define NULL_PTR 0

#define TIMEUS(TS) (1000000 * TS.tv_sec + TS.tv_usec)

class MyTimer
{
	public:
	
	#ifdef MY_GNU
	timeval start,stop;
	#else
	//#ifdef MY_MSVC
	time_t start,stop;
	#endif
	
	double elapsed;
	
	void start_timer()
	{
		#ifdef MY_GNU
		gettimeofday(&start,0);
		#else
		//#ifdef MY_MSVC
		time(&start);
		#endif
	}
	
	void stop_timer()
	{
		#ifdef MY_GNU
		gettimeofday(&stop,0);
		#else
		//#ifdef MY_MSVC
		time(&stop);
		#endif
	}
	
	double elapsed_time()
	{
		#ifdef MY_GNU
		elapsed=(double)TIMEUS(stop)-(double)TIMEUS(start);
		elapsed/=1000.0;
		#else
		//#ifdef MY_MSVC
		time(&stop);
		elapsed=((double)stop-(double)start)*1000.0;
		#endif
		
		return elapsed;
	}
	
	MyTimer()
	{
		start_timer();
	}
};

const bool DO_CREATE=true;
const bool DONT_CREATE=false;

typedef unsigned int MyHashPtr;
typedef unsigned int MyHashKey;
typedef unsigned int MyHashMask;

template<class VALUE,int set_queue_length>
class MyQueue
{
	public:
	int queue_length;
	int queue_current_length;
	
	char name[100];
	
	pthread_mutex_t queue_mutex;
	
	VALUE queue[set_queue_length];
	
	MyQueue(const char* set_name)
	{
	
		pthread_mutex_init(&queue_mutex, NULL);
	
		queue_length=set_queue_length;
		queue_current_length=0;
		
		strcpy(name,set_name);
	}
	
	void shift_right()
	{
		for(int i=queue_length-1;i>0;i--)
		{
			queue[i]=queue[i-1];
		}
	}
	
	void shift_left()
	{
		for(int i=0;i<(queue_length-1);i++)
		{
			queue[i]=queue[i+1];
		}
	}
	
	bool enqueue(VALUE* value)
	{
	
		if(queue_current_length>=queue_length)
		{
			return false;
		}
		else
		{
			pthread_mutex_lock(&queue_mutex);
			
			shift_right();
			memcpy(&queue[0],value,sizeof(VALUE));
			queue_current_length++;
			
			pthread_mutex_unlock(&queue_mutex);
			return true;
		}
	}
	
	bool dequeue(VALUE* container)
	{
	
		if(queue_current_length==0)
		{
			return false;
		}
		else
		{
			pthread_mutex_lock(&queue_mutex);
			
			--queue_current_length;
			
			*container=queue[queue_current_length];
			
			pthread_mutex_unlock(&queue_mutex);
			return true;
		}
	}
	
	bool pending()
	{
		return (queue_current_length>0);
	}
	
};

template<class KEY,class VALUE,int set_hash_size_shift,int set_value_size>
class MyHash
{

	public:
	int key_size;
	MyHashMask hash_mask;
	int hash_size;
	int ptrs_buffer_size;
	int value_size;
	int value_buffer_size;
	int total_buffer_size;
	int value_alloc_ptr;
	int value_alloc_ptr_last_index;
	MyHashPtr* hash_ptrs;
	VALUE* hash_values;
	MyHashKey calc_hash_key(void* key_ptr)
	{
		MyHashKey key=XXH32(key_ptr,key_size,0)&hash_mask;
		return key;
	}
	VALUE* look_up(KEY* key_ptr,bool create)
	{
		MyHashKey key=calc_hash_key(key_ptr);
		#ifdef MYHASH_DEBUG
		char key_puff[key_size+1];
		key_puff[key_size]=0;
		memcpy(key_puff,key_ptr,key_size);
		cout << "look up " << key_puff << " hash key = " << key << (create?" create":" dont create") << endl;
		#endif
		int hash_ptr=hash_ptrs[key];
		if(hash_ptr==NULL_PTR)
		{
			#ifdef MYHASH_DEBUG
			cout << "key does not exist" << endl;
			#endif
			if(!create)
			{
				#ifdef MYHASH_DEBUG
				cout << "no need to create, return NULL_PTR" << endl;
				#endif
				return NULL_PTR;
			}
			else
			{
				#ifdef MYHASH_DEBUG
				cout << "attempt to create key" << endl;
				#endif
				if(value_alloc_ptr>value_alloc_ptr_last_index)
				{
					#ifdef MYHASH_DEBUG
					cout << "out of memory, return NULL_PTR" << endl;
					#endif
					return NULL_PTR;	
				}
				else
				{
					hash_ptrs[key]=value_alloc_ptr;
					VALUE* value_ptr=(VALUE*)(hash_values+value_alloc_ptr);
					memcpy(value_ptr->id,key_ptr,key_size);
					value_ptr->next=NULL_PTR;
					value_alloc_ptr++;
					#ifdef MYHASH_DEBUG
					cout << "key created, return " << value_ptr << endl;
					#endif
					return value_ptr;
				}
			}
		}
		else
		{
			#ifdef MYHASH_DEBUG
			cout << "key exists, searching for match" << endl;
			#endif
			VALUE* value_ptr=(VALUE*)(hash_values+hash_ptr);
			while((value_ptr->next!=NULL_PTR)&&(0!=memcmp(value_ptr->id,key_ptr,key_size)))
			{
				#ifdef MYHASH_DEBUG
				cout << "match failed, jumping to next value" << endl;
				#endif
				value_ptr=(VALUE*)(hash_values+value_ptr->next);
			}
			if(0!=memcmp(value_ptr->id,key_ptr,key_size))
			{
				#ifdef MYHASH_DEBUG
				cout << "no match found" << endl;
				#endif
				if(!create)
				{
					#ifdef MYHASH_DEBUG
					cout << "no need to create, return NULL_PTR" << endl;
					#endif
					return NULL_PTR;
				}
				else
				{
					if(value_alloc_ptr>value_alloc_ptr_last_index)
					{
						#ifdef MYHASH_DEBUG
						cout << "out of memory, return NULL_PTR" << endl;
						#endif
						return NULL_PTR;	
					}
					else
					{
						VALUE* new_value_ptr=(VALUE*)(hash_values+value_alloc_ptr);
						memcpy(new_value_ptr->id,key_ptr,key_size);
						new_value_ptr->next=NULL_PTR;
						value_ptr->next=value_alloc_ptr;
						value_alloc_ptr++;
						#ifdef MYHASH_DEBUG
						cout << "key created, return " << new_value_ptr << endl;
						#endif
						return new_value_ptr;
					}
				}
			}
			else
			{
				#ifdef MYHASH_DEBUG
				cout << "match was found, return " << value_ptr << endl;
				#endif
				return value_ptr;
			}
		}
	}
	void init()
	{
		memset(hash_ptrs,0,ptrs_buffer_size);
		value_alloc_ptr=1;
	}
	MyHash()
	{
	
		key_size=sizeof(KEY);
		hash_size=(1 << set_hash_size_shift);
		hash_ptrs=new MyHashPtr[hash_size];
		ptrs_buffer_size=hash_size*sizeof(MyHashPtr);
		value_size=set_value_size;
		value_alloc_ptr_last_index=value_size-1;
		hash_values=new VALUE[value_size];
		value_buffer_size=value_size*sizeof(VALUE);
		total_buffer_size=ptrs_buffer_size+value_buffer_size;
		hash_mask=(MyHashMask)(hash_size-1);
		init();
		
	}
};

template<class KEY,class VALUE,int set_hash_size_shift>
class KickHash
{

	public:
	int key_size;
	MyHashMask hash_mask;
	int hash_size;
	int buffer_size;
	VALUE* hash_values;
	
	MyHashKey calc_hash_key(void* key_ptr)
	{
		MyHashKey key=XXH32(key_ptr,key_size,0)&hash_mask;
		return key;
	}
	
	void init()
	{
		memset(hash_values,0,buffer_size);
	}
	
	KickHash()
	{
	
		key_size=sizeof(KEY);
		hash_size=(1 << set_hash_size_shift);
		hash_values=new VALUE[hash_size];
		buffer_size=hash_size*sizeof(VALUE);
		hash_mask=(MyHashMask)(hash_size-1);
		init();
		
	}
	
	VALUE* look_up(KEY* key_ptr)
	{
		MyHashKey key=calc_hash_key(key_ptr);
		return &hash_values[key];
	}
	
};

}

#endif