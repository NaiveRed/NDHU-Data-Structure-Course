#include"DoublyLinkedList.h"
#include<stdlib.h>
#include<stdio.h>

node* createNode()
{
	//allocate the memory
	node *n = (node*)malloc(sizeof(node));

	if (!n)//allocate failed
		exit(EXIT_FAILURE);

	n->next = n->prev = n;//node�@�}�l prev , next�����V�ۤv

	return n;
}
duList* createDuList()
{
	//allocate memory
	duList* dlist = (duList*)malloc(sizeof(duList));

	if (!dlist)//allocate failed
		exit(EXIT_FAILURE);

	dlist->head = createNode();//head node �b�@�}�lprev,next���O���V�ۤv

	return dlist;
}
void insert(node* n, element ele)
{
	node* tar = createNode();
	tar->data = ele;

	//�N�snode��prev,next����������a��
	tar->next = n->next;
	tar->prev = n;

	//��索�k��Ǫ�node
	n->next->prev = tar;
	n->next = tar;

}
bool isEmpty(duList* list)
{
	return list->head->next == list->head ? true : false;//�p�Ghead��next,prev�����V�ۤv�Alist����
}
void push_back(duList* list, element ele)
{
	if (list)
	{
		node* tar = createNode();
		tar->data = ele;
		if (!isEmpty(list))
		{
			//�����tail��next�A�ñNtar�����̧���
			node* tail = list->head->prev;
			tail->next = tar;

			tar->prev = tail;
			tar->next = list->head;

			//�Nhead node ��prev�令�s������
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
			//������̫e�ݪ�prev�A�ñNtar�����̫e��
			node* begining = list->head->next;
			begining->prev = tar;

			tar->next = begining;
			tar->prev = list->head;

			//�Nhead node ��next�令�s���e��
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
		//�q�Y������A����^head
		node* n = list->head->next;
		while (n != list->head)
		{
			cb(n->data);
			n = n->next;
		}
	}
	else
	{
		//�q�����^�Y�A����^head
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

	node *tar = list->head->prev;//��������tail

	tar->prev->next = list->head;//�s��tail->next���Vhead
	list->head->prev = tar->prev;//�Nhead->prev���V�s��tail

	free(tar);
}
void remove_front(duList* list)
{
	if (isEmpty(list))
		return;
	
	node *tar = list->head->next;//��������front

	tar->next->prev = list->head;//�s��front��prev���Vhead
	list->head->next = tar->next;//�Nhead->next���V�s��front

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
		while (n != list->head)//head������
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