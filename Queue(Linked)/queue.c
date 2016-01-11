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
	//�Ĥ@��rear�Mfront�����|�sdata�A���Vheadnode
	Q->front = Q->rear = (node*)malloc(sizeof(node));
	if (!Q->front)//allocate failed
		exit(EXIT_FAILURE);

	Q->front->link = NULL;//Q->rear->link = NULL;
}
bool isEmpty(queue* Q)
{
	//q->front->link = NULL
	return (Q->front == Q->rear) ? true : false;//�p�Gfront�Mrear�����Vheadnode�Aqueue�N�O�Ū�
}
void enQueue(queue* Q, element ele)
{
	node *tar = createNode();
	tar->data = ele;

	Q->rear->link = tar;//�ثerear��link���V�s��node
	Q->rear = tar;//��rear����̷s��node
}
bool deQueue(queue* Q)
{
	if (isEmpty(Q))//queue is empty
		return false;

	node* temp = Q->front->link;//���V�Ĥ@����ơA�]�N�Oheadnode���U�@��
	Q->front->link = temp->link;//�Nheadnode���U�@�ӫ��V�n�R�����U�@��

	if (Q->rear == temp)//�p�G�R���O�̫�@�ӡAqueue���šAreset q->rear
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
	Q->rear = Q->front;//�Nrear���Vfront(headnode)
	Q->front->link = NULL;//�Nheadnode���U�@�ӫ��VNULL

	while (tar)//�M��
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

