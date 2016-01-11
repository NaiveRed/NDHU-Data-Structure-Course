#include"Heap.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define PARENT(i) ((i)>>1)//i/2
#define L_CHILD(i) ((i)<<1)//2*i
#define R_CHILD(i) ((i)<<1+1)//2*i+1

heap* createHeap(int size)
{
	heap* h = (heap*)malloc(sizeof(heap));
	element *array = (element*)malloc(sizeof(element)*(size + 1));//first is 1

	h->array = array;
	h->maxSize = size;
	h->size = 0;

	return h;
}
bool heapFull(heap* h)
{
	if (!h)
	{
		fprintf(stderr, "ERROR");
		exit(EXIT_FAILURE);//pointer is null
	}
	else
		if (h->maxSize == h->size)
			return true;

	return false;
}
bool heapEmpty(heap* h)
{
	if (!h)
	{
		fprintf(stderr, "ERROR");
		exit(EXIT_FAILURE);//pointer is null
	}
	else
		if (!h->size)
			return true;

	return false;

}
bool insertMaxHeap(heap *h, element ele)
{
	if (heapFull(h))
		return false;

	int idx = ++h->size;

	while (idx != 1 && ele.val > h->array[PARENT(idx)].val)
	{
		h->array[idx].val = h->array[PARENT(idx)].val;
		idx = PARENT(idx);
	}

	h->array[idx] = ele;

	return true;
}
element popMaxHeap(heap *h)
{
	if (heapEmpty(h))
	{
		fprintf(stderr, "Heap is empty.");
		exit(EXIT_FAILURE);
	}

	element top = h->array[1];

	element temp = h->array[h->size];

	h->size--;

	int parent = 1, child = 2;

	while (child <= h->size)
	{
		//find the bigger child from current parent
		if (child < h->size&&h->array[child].val < h->array[child + 1].val)//L_CHILD(parent),R_CHILD(parent)
			child++;

		if (temp.val > h->array[child].val)//欲替換的目標已為最大 
			break;

		h->array[parent] = h->array[child];//向下繼續修正 
		parent = child;

		child = L_CHILD(child);
	}

	h->array[parent] = temp;

	return top;
}
bool insertMinHeap(heap *h, element ele)
{
	if (heapFull(h))
		return false;

	int idx = ++h->size;

	while (idx != 1 && ele.val < h->array[PARENT(idx)].val)
	{
		h->array[idx].val = h->array[PARENT(idx)].val;
		idx = PARENT(idx);
	}

	h->array[idx] = ele;

	return true;
}
element popMinHeap(heap *h)
{
	if (heapEmpty(h))
	{
		fprintf(stderr, "Heap is empty.");
		exit(EXIT_FAILURE);
	}

	element top = h->array[1];

	element temp = h->array[h->size];

	h->size--;

	int parent = 1, child = 2;

	while (child <= h->size)
	{
		//find the smaller child from current parent
		if (child < h->size&&h->array[child].val > h->array[child + 1].val)//L_CHILD(parent),R_CHILD(parent)
			child++;

		if (temp.val < h->array[child].val)//欲替換的目標已為最小 
			break;

		h->array[parent] = h->array[child];//向下繼續修正 
		parent = child;

		child = L_CHILD(child);
	}

	h->array[parent] = temp;

	return top;
}
void clearHeap(heap *h)
{
	if (h)
	{
		element ele;
		ele . val = 0;
		int i; 
		for(i = 0 ; i <= h->size ; i++)//所有element的值都為0 
			h->array[i] = ele;
			
		h -> size = 0;
	}
}
void traverse(heap *h, void(*cb)(element))
{
	if(h)
	{
		int i, size = h->size;
		for (i = 1; i <= size; i++)
			cb(h->array[i]);
	}
}
void destroyHeap(heap* h)
{
	if(h)
	{
		free(h->array);
		free(h);
	 } 
}

