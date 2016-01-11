#include"queue.h"
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

node* createNode()
{
	//allocate the memory
	node *temp = (node*)malloc(sizeof(node));
	if (!temp)//allocate failed
		exit(EXIT_FAILURE);
		
	temp->link = NULL;
	return temp;
}
queue* createQueue()
{
	queue* Q = (queue*)malloc(sizeof(queue));
	if (!Q)//allocate failed
		exit(EXIT_FAILURE);

	//init
	initQueue(Q);

	return Q;
}
void initQueue(queue* Q)
{
	//第一個rear和front都不會存data，指向headnode
	Q->front = Q->rear = (node*)malloc(sizeof(node));
	if (!Q->front)//allocate failed
		exit(EXIT_FAILURE);

	Q->front->link = NULL;//Q->rear->link = NULL;
}
bool isEmpty(queue* Q)
{
	//q->front->link = NULL
	return (Q->front == Q->rear) ? true : false;//如果front和rear都指向headnode，queue就是空的
}
void enQueue(queue* Q, element ele)
{
	node *tar = createNode();
	tar->data = ele;

	Q->rear->link = tar;//目前rear的link指向新的node
	Q->rear = tar;//把rear移到最新的node
}
bool deQueue(queue* Q)
{
	if (isEmpty(Q))//queue is empty
		return false;

	node* temp = Q->front->link;//指向第一筆資料，也就是headnode的下一個
	Q->front->link = temp->link;//將headnode的下一個指向要刪掉的下一個

	if (Q->rear == temp)//如果刪的是最後一個，queue為空，reset q->rear
		Q->rear = Q->front;

	free(temp);
	
	return true;
}
element getElement(queue* Q)
{
	if (isEmpty(Q))
	{
		//error message
		exit(EXIT_FAILURE);
	}
	element ele= Q->front->link->data;

	return ele;
}
int getLength(queue* Q)
{
	int length = 0;
	node *temp = Q->front->link;
	
	while(temp)
	{
		length++;
		temp=temp->link;
	}	
	
	return length;
}
void clearQueue(queue* Q)
{
	node *tar = Q->front->link;
	Q->rear = Q->front;//將rear指向front(headnode)
	Q->front->link = NULL;//將headnode的下一個指向NULL

	while (tar)//清空
	{
		node *next = tar->link;
		free(tar);
		tar = next;
	}
	

}
void destroyQueue(queue* Q)
{
	while (Q->front)//free all node
	{
		node *tar = Q->front->link;
		free(Q->front);
		Q->front = tar;
	}

	free(Q);//free queue
}
void traverseQueue(queue* Q, void(*cb)(element))
{
	node *tar = Q->front->link;

	while (tar)
	{
		cb(tar->data);//callback function
		tar = tar->link;
	}

}

