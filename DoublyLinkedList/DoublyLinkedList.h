#ifndef _DLIST_H
#define _DLIST_H
#include<stdbool.h>

//implement doubly Linked list
typedef struct Element
{
	int val;

}element;


typedef struct Node
{
	element data;
	struct Node *next;
	struct Node *prev;
}node;

typedef struct DoublyLinkedList
{
	//儲存資料後head->prev為tail,head->next為front
	node* head;

}duList;

node* createNode();//init
duList* createDuList();//init

bool isEmpty(duList* list);
void insert(node* n,element ele);//insert data after n node
void push_back(duList* list, element ele);//insert data at tail of doubly linked list
void push_front(duList* list, element ele);//insert data at begining of doubly linked list
void remove_back(duList* list);//remove the node of tail
void remove_front(duList* list);//remove the node of begining
int searchDuList(duList* list, int val);//return the offset position of val,first is 1.return NULL ,if not in list.

element getBack(duList* list);//return the tail element
element getFront(duList* list);//return the front element
element getElement(duList* list,int i);//回傳從頭數第i個位置的element

void traverse(duList* list, bool opt, void(*cb)(element));//如果opt是true,從前面到後面;如果是false,從後面到前面

void clearDuList(duList* list);//清空list
void destroyDuList(duList* list);//摧毀list

#endif
