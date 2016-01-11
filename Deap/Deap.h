#ifndef DEAP_H_
#define DEAP_H_
#include<stdbool.h>

typedef struct deap
{
	int* arr;
	int size;
	int max_size;
	
}Deap;

Deap* createDeap(int size);
bool deapIsFull(Deap* d);
bool deapIsEmpty(Deap* d);
bool InMaxHeap(int idx);//return false if in min heap
int correspondToMax(int size, int idx);//return the partner of min in max heap,size 為目前的deap的範圍
int correspondToMin(int idx);//return the partner of max in min heap
void insertMinHeap(Deap* d,int idx,int num);//utility function to insert in min heap
void insertMaxHeap(Deap* d, int idx, int num);//utility function to insert in max heap
bool insertDeap(Deap* d,int num);//return false if deap is full or didn't init
int popMinHeap(Deap* d);
int popMaxHeap(Deap* d);
int searchDeap(Deap* d, int num);//return the index of num ,if not in deap return 0
void printDeap(Deap* d);
void destroyDeap(Deap *d);

#endif
