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

void clearStack(stack* s);//清空stack
void destroyStack(stack* s);//摧毀stack
void traverseStack(stack* s,void(*cb)(element));//對每個element call cb

#endif
