#include "Dequeue.h"
#include <stdlib.h>
#include <assert.h>

void initialise(queue** q)
{
	*q = malloc(sizeof(queue));
	(*q)->head = (*q)->tail = NULL;
	(*q)->size = 0;
}

void addDQ(queue* q, void* data)
{
	assert(q);
	if(!(q->tail))
	{
		q->head = q->tail = malloc(sizeof(queue_node_t));
		q->head->data = data;
	}
	else
	{
		q->tail->next = malloc(sizeof(queue_node_t));
		q->tail->next->data = data;
		q->tail = q->tail->next;
	}
}

void* dequeueDQ(queue* q)
{
	assert(q && q->tail);
	void* data = NULL;
	if(q->head == q->tail)
	{
		data = q->tail->data;
		q->head = q->tail = NULL;
	}
	else
	{
		data = q->tail->data;
		queue_node_t* curr = q->head;
		while(curr->next != q->tail) curr = curr->next;
		free(q->tail);
		q->tail = curr;
	}
	return data;
}
