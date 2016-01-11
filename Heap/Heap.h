#ifndef _HEAP_H
#define _HEAP_H
#include<stdbool.h>

typedef struct Element
{
	int val;
	//others

}element;

typedef struct Heap
{
	element* array;
	int size;
	int maxSize;

}heap;

heap* createHeap(int size);
bool heapFull(heap* h);
bool heapEmpty(heap* h);

bool insertMaxHeap(heap *h, element ele);//return false if insert fail ,otherwise return true
element popMaxHeap(heap *h);//return the original top

bool insertMinHeap(heap *h, element ele);//return false if insert fail ,otherwise return true
element popMinHeap(heap *h);//return the original top

void traverse(heap *h, void(*cb)(element));//call cb for every elements
void destroyHeap(heap *h);//ºR·´heap 
void clearHeap(heap *h);//²MªÅheap 

#endif
