#ifndef _H_QUEUE
#define _H_QUEUE
#include<stdbool.h>

typedef struct Element
{
	int val;

}element;

typedef struct Node
{
	element data;
	struct Node* link;

}node;

typedef struct Queue
{
	node *front;
	node *rear;

}queue;

node* createNode();
queue* createQueue();
void initQueue(queue* Q);
bool isEmpty(queue* Q);//return true if queue is empty,otherwise return false
void enQueue(queue* Q, element ele);//add element 
bool deQueue(queue* Q);//return false if queue is empty
element getElement(queue* Q);//get the first element
int getLength(queue* Q);//return the length of queue
void clearQueue(queue* Q);//²MªÅqueue¡A«DºR·´
void destroyQueue(queue* Q);//ºR·´queue
void traverseQueue(queue* Q,void(*cb)(element));//call cb for all element

#endif
