#include "Dequeue.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

void initialise(queue* q)
{
	q->head = NULL;
	q->tail = NULL;
	q->size = 0;
}

void addDQ(queue* q, void* data)
{
	assert(q != NULL);

	if(!(q->head))
	{
		q->head = malloc(sizeof(queue_node_t));
		q->tail = q->head;
		q->head->data = data;
	}
	else
	{
		q->tail->next = malloc(sizeof(queue_node_t));
		q->tail->next->data = data;
		q->tail = q->tail->next;
	}
	q->size++;
}

void* dequeueDQ(queue* q)
{
	assert(q && q->head);
	void* data = NULL;
	if(q->head == q->tail)
	{
		data = q->tail->data;
		q->head = NULL;
		q->tail = NULL;
	}
	else
	{
		data = q->head->data;
		queue_node_t* curr = q->head;
		q->head = q->head->next;
		free(curr);
	}
	q->size--;
	return data;
}

int sizeDQ(queue* q)
{
	return q->size;
}
