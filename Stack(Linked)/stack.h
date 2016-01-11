#ifndef _STACK_H_
#define _STACK_H_
#include<stdbool.h>

//implement stack by single linked list
typedef struct Element
{
	int val;

}element;

typedef struct Node
{
	struct Node* link;
	element data;

}node;

typedef struct Stack
{
	node* top;
	int size;

}stack;

stack* createStack();//init
node* createNode();//init

bool isEmpty(stack* s);

void push(stack* s, element ele);
void pop(stack* s);

element getTop(stack* s);//if stack is empty,exit the program
int getSize(stack* s);//get size of stack 

void clearStack(stack* s);//�M��stack
void destroyStack(stack* s);//�R��stack
void traverseStack(stack* s,void(*cb)(element));//��C��element call cb

#endif
