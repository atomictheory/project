#ifndef UNBUFSTDIO_H
#define UNBUFSTDIO_H

namespace UnbufstdioSpace
{

	const int IO_QUEUE_LENGTH=(1000);
	
	const int ITEM_BUFFER_SIZE=(1000);

	struct Item
	{
		char buffer[ITEM_BUFFER_SIZE];
		char token[ITEM_BUFFER_SIZE];
		int ptr;
		char* get_token();
	};
	
	extern void(*stdin_dequeue_callback)(Item);

	extern void init();
	
	extern bool stdin_dequeue(Item*);
	extern bool stdin_pending();

}

#endif