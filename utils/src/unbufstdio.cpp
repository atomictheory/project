#include "../../setup.h"

#include "../include/unbufstdio.h"

#include "../include/myhash.h"

#include <stdio.h>
#include <iostream>

#ifdef MY_MSVC
#include <Windows.h>
#endif

using namespace std;
using namespace MyHashSpace;

namespace UnbufstdioSpace
{

	MyQueue<Item,IO_QUEUE_LENGTH> stdin_queue("stdin");
	
	pthread_t stdin_thread;
	
	void(*stdin_dequeue_callback)(Item);
	
	void* stdin_thread_func(void* void_ptr)
	{	
	
		while(true)
		{
		
			Item item;
			
			cin.getline(item.buffer,(ITEM_BUFFER_SIZE-1));
			item.ptr=0;
			
			stdin_queue.enqueue(&item);
			
			stdin_dequeue_callback(item);
			
			Sleep(50);

		}
		
	}
	
	bool stdin_dequeue(Item* item)
	{
		return stdin_queue.dequeue(item);
	}
	
	bool stdin_pending()
	{
		return stdin_queue.pending();
	}
	
	char* Item::get_token()
	{
		int token_ptr=0;
		while((buffer[ptr])&&(buffer[ptr]!=' ')&&(ptr<(ITEM_BUFFER_SIZE-1)))
		{
			token[token_ptr++]=buffer[ptr++];
		}
		while((buffer[ptr]==' ')&&(ptr<(ITEM_BUFFER_SIZE-1))){ptr++;}
		token[token_ptr]=0;
		return token;
	}

	void init()
	{
		setbuf(stdin, NULL);
		setbuf(stdout, NULL);
		cout.rdbuf()->pubsetbuf(NULL, 0);
		cin.rdbuf()->pubsetbuf(NULL, 0);
		
		if(pthread_create(&stdin_thread, NULL, stdin_thread_func, NULL))
		{
		
			cout << "Error creating thread." << endl;
			exit(0);

		}
	}

}