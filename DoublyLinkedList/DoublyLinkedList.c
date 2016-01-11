#include"DoublyLinkedList.h"
#include<stdlib.h>
#include<stdio.h>

node* createNode()
{
	//allocate the memory
	node *n = (node*)malloc(sizeof(node));

	if (!n)//allocate failed
		exit(EXIT_FAILURE);

	n->next = n->prev = n;//node一開始 prev , next都指向自己

	return n;
}
duList* createDuList()
{
	//allocate memory
	duList* dlist = (duList*)malloc(sizeof(duList));

	if (!dlist)//allocate failed
		exit(EXIT_FAILURE);

	dlist->head = createNode();//head node 在一開始prev,next都是指向自己

	return dlist;
}
void insert(node* n, element ele)
{
	node* tar = createNode();
	tar->data = ele;

	//將新node的prev,next指到相應的地方
	tar->next = n->next;
	tar->prev = n;

	//更改左右兩旁的node
	n->next->prev = tar;
	n->next = tar;

}
bool isEmpty(duList* list)
{
	return list->head->next == list->head ? true : false;//如果head的next,prev都指向自己，list為空
}
void push_back(duList* list, element ele)
{
	if (list)
	{
		node* tar = createNode();
		tar->data = ele;
		if (!isEmpty(list))
		{
			//更改原先tail的next，並將tar換成最尾端
			node* tail = list->head->prev;
			tail->next = tar;

			tar->prev = tail;
			tar->next = list->head;

			//將head node 的prev改成新的尾端
			list->head->prev = tar;
		}
		else
		{
			list->head->next = list->head->prev = tar;
			tar->next = tar->prev = list->head;
		}
	}
}
void push_front(duList* list, element ele)
{
	if (list)
	{
		node* tar = createNode();
		tar->data = ele;
		if (!isEmpty(list))
		{
			//更改原先最前端的prev，並將tar換成最前端
			node* begining = list->head->next;
			begining->prev = tar;

			tar->next = begining;
			tar->prev = list->head;

			//將head node 的next改成新的前端
			list->head->next = tar;
		}
		else
		{
			list->head->next = list->head->prev = tar;
			tar->next = tar->prev = list->head;
		}
	}
}
element getBack(duList* list)
{
	return list->head->prev->data;
}
element getFront(duList* list)
{
	return list->head->next->data;
}
element getElement(duList* list, int i)
{

	if (isEmpty(list)||i<1)
	{
		fprintf(stderr, "ERROR");
		exit(EXIT_FAILURE);
	}

	node* n = list->head->next;
	int j;
	for (j = 1; j < i; j++)
	{
		n = n->next;
	
		if (n == list->head)
		{
			fprintf(stderr, "ERROR");
			exit(EXIT_FAILURE);
		}

	}

	return n->data;

}
void traverse(duList* list, bool opt, void(*cb)(element))
{
	if (opt)
	{
		//從頭走到尾，直到回head
		node* n = list->head->next;
		while (n != list->head)
		{
			cb(n->data);
			n = n->next;
		}
	}
	else
	{
		//從尾走回頭，直到回head
		node* n = list->head->prev;
		while (n != list->head)
		{
			cb(n->data);
			n = n->prev;
		}
	}
}
void remove_back(duList* list)
{
	if (isEmpty(list))
		return;

	node *tar = list->head->prev;//欲移除的tail

	tar->prev->next = list->head;//新的tail->next指向head
	list->head->prev = tar->prev;//將head->prev指向新的tail

	free(tar);
}
void remove_front(duList* list)
{
	if (isEmpty(list))
		return;
	
	node *tar = list->head->next;//欲移除的front

	tar->next->prev = list->head;//新的front的prev指向head
	list->head->next = tar->next;//將head->next指向新的front

	free(tar);
}
int searchDuList(duList* list, int val)
{
	if (!isEmpty(list))
	{
		int count = 1;
		node* n = list->head->next;
		while (n != list->head)
		{
			if (n->data.val == val)
			{
				return count;
			}
			else
			{
				count++;
				n = n->next;
			}
		}
	}

	return NULL;
}
void clearDuList(duList* list)
{
	if (!isEmpty(list))
	{
		node *n = list->head->next;
		while (n != list->head)//head不釋放
		{
			node *temp = n->next;
			free(n);
			n = temp;
		}

		list->head->next = list->head->prev = list->head;
	}
}
void destroyDuList(duList* list)
{
	clearDuList(list);
	free(list->head);
	free(list);
}