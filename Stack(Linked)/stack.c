#include"stack.h"
#include<stdlib.h>
#include<stdio.h>

stack* createStack()
{
	//allocate memory
	stack *s = (stack*)malloc(sizeof(stack));

	if (!s)//allocate failed
		exit(EXIT_FAILURE);

	s->top = NULL;//初始值為NULL
	s->size = 0;

	return s;
}

node* createNode()
{
	//allocate memory
	node *n = (node*)malloc(sizeof(node));

	if (!n)//allocate failed
		exit(EXIT_FAILURE);

	n->link = NULL;

	return n;
}
bool isEmpty(stack* s)
{
	return s->size ? false : true;//if size equal to zero ,the stack is empty
}
void push(stack* s, element val)
{
	node *n = createNode();

	n->data = val;

	n->link = s->top;
	s->top = n;//top變為新增的node

	s->size++;

}
void pop(stack* s)
{
	if (s->top)//!isEmpty(s)
	{
		node* n = s->top;
		s->top = n->link;//top變為下一個
		s->size--;

		free(n);
	}
}
element getTop(stack* s)
{
	if (s->top)
		return s->top->data;

	//stack is empty
	fprintf(stderr,"ERROR");
	exit(EXIT_FAILURE);
}
int getSize(stack* s)
{
	return s->size;
}
void clearStack(stack* s)
{
	if (s)
		while (s->top)
			pop(s);

}
void destroyStack(stack* s)
{
	if (s)
	{
		clearStack(s);//先清空 
		free(s);
	}
}
void traverseStack(stack* s, void(*cb)(element))
{
	node *temp = s->top;
	while (temp)
	{
		cb(temp->data);//callback funtion for every element
		temp = temp->link;
	}
}
