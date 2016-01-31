#ifndef DEQUEUE_H_
#define DEQUEUE_H_
/*	USAGE

 	queue q;
	initialise(&q);
	int test1 = 1;
	addDQ(&q, &test1);
	printf("1st value is: %d\n", *((int *)dequeueDQ(&q)));

	int test2 = 2;
	addDQ(&q, &test2);
	printf("2nd value is: %d\n", *((int *)dequeueDQ(&q)));


	int test3 = 3;
	addDQ(&q, &test3);
	printf("3rd value is: %d\n", *((int *)dequeueDQ(&q)));

 */
typedef struct queue_node_s
{
	void* data;
	struct queue_node_s* next;
} queue_node_t;

typedef struct queue
{
	queue_node_t* head;
	queue_node_t* tail;
	int size;
} queue;

void initialise(queue*);

void addDQ(queue*,void*);

void* dequeueDQ(queue*);

int sizeDQ(queue* q);


#endif /* DEQUEUE_H_ */
