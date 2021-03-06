#include"Deap.h"
#include<stdlib.h>
#define PARENT(i) ((i)>>1)//i/2
#define SIZE_TO_IDX(size) ((size)+1)

Deap* createDeap(int size)
{
	Deap* deap = (Deap*)malloc(sizeof*deap);
	deap->arr = (int*)calloc(size + 2, sizeof(int));//0,1不存放東西,1為根
	deap->max_size = size;
	deap->size = 0;

	return deap;
}
bool deapIsFull(Deap* d)
{
	return d->max_size == d->size;
}
bool deapIsEmpty(Deap* d)
{
	return d->size ? false : true;
}
bool InMaxHeap(int idx)
{
	while (idx > 3)
		idx /= 2;
	return idx == 3;
}
int correspondToMax(int size, int idx)
{
	/*
	log is base 2.
	x = (n + 2^((logn)-1))
	if x > 目前長度
	x /= 2
	*/
	if (idx == 2)
		return 2;
	int i;
	for (i = 2; i * 2 <= idx; i *= 2);
	i /= 2;
	if (idx + i > size)//如果對過去的Max heap已超出範圍就要除以2
		return (idx + i) / 2;
	return idx + i;
}
int correspondToMin(int idx)
{
	/*
	log is base 2.
	f(n) = n - 2^((logn)-1)
	*/
	int i;
	for (i = 2; i * 2 <= idx; i *= 2);

	return idx - i / 2;
}
void insertMinHeap(Deap* d, int idx, int num)
{
	while (idx > 2 && num < d->arr[PARENT(idx)])//the root of min heap is 2
	{
		d->arr[idx] = d->arr[PARENT(idx)];
		idx = PARENT(idx);
	}

	d->arr[idx] = num;

}
void insertMaxHeap(Deap* d, int idx, int num)
{
	while (idx > 3 && num > d->arr[PARENT(idx)])//the root of max heap is 3
	{
		d->arr[idx] = d->arr[PARENT(idx)];
		idx = PARENT(idx);
	}

	d->arr[idx] = num;

}
bool insertDeap(Deap* d, int num)
{
	if (deapIsFull(d) || !d)
		return false;

	if (deapIsEmpty(d))
	{
		d->arr[2] = num;
		d->size++;
	}
	else
	{
		int idx = SIZE_TO_IDX(++d->size);
		int i;
		switch (InMaxHeap(idx))
		{
			//in max heap
		case true:
			i = correspondToMin(idx);
			/*
			比較在min heap(MinH)裡相對應的數字
			(1)
			如果MinH裡的比num大，就交換他們，並把新的插入MinH裡
			(2)
			如果MinH裡的比num小，就直接插入Max Heap裡
			*/
			if (num < d->arr[i])
			{
				d->arr[idx] = d->arr[i];
				insertMinHeap(d, i, num);
			}
			else
				insertMaxHeap(d, idx, num);
			break;
			//in min heap
		case false:
			i = correspondToMax(idx, idx);
			/*
			比較在max heap(MaxH)裡相對應的數字
			(1)
			如果MaxH裡的比num小，就交換他們，並把新的插入MaxH裡
			(2)
			如果MaxH裡的比num大，就直接插入Min Heap裡
			*/
			if (num > d->arr[i])
			{
				d->arr[idx] = d->arr[i];
				insertMaxHeap(d, i, num);
			}
			else
				insertMinHeap(d, idx, num);
		}
	}

	return true;
}
int popMinHeap(Deap* d)
{
	if (!d || deapIsEmpty(d))
	{
		//error message
		exit(EXIT_FAILURE);
	}

	int min = d->arr[2];
	int temp = d->arr[SIZE_TO_IDX(d->size)];
	int size = SIZE_TO_IDX(--d->size);//最後一個拿來重填

	int p, c;//parent,child
	for (p = 2; p * 2 <= size; p = c)//min heap的第一個pop掉了，重新調整min heap
	{
		c = p * 2;
		if (c + 1 <= size)
			if (d->arr[c] > d->arr[c + 1])
				c++;
		d->arr[p] = d->arr[c];
	}

	int partner = correspondToMax(size, p);//調整完後的空格，partner為對應max heap內的位置
	if (d->arr[partner] < temp)
	{
		/*
		比max heap對應的大:
		將min heap的空格填入max partner的數字
		將原先deap的最後一個元素插入max heap
		*/
		d->arr[p] = d->arr[partner];
		insertMaxHeap(d, partner, temp);
	}
	else
		insertMinHeap(d, p, temp);//將min heap的空格填入原先的最後一個

	return min;
}
int popMaxHeap(Deap* d)
{
	if (!d || deapIsEmpty(d))
	{
		//error message
		exit(EXIT_FAILURE);
	}
	else if (d->size == 1)//只有一個時，在min heap
		return popMinHeap(d);

	int max = d->arr[3];
	int temp = d->arr[SIZE_TO_IDX(d->size)];
	int size = SIZE_TO_IDX(--d->size);//最後一個拿來重填

	int p, c;//parent,child
	for (p = 3; p * 2 <= size;)//max heap的第一個pop掉了，重新調整max heap
	{
		c = p * 2;
		if (c + 1 <= size)
			if (d->arr[c] < d->arr[c + 1])
				c++;
		d->arr[p] = d->arr[c];
		p = c;
	}

	int partner = correspondToMin(p);//調整完後的空格，partner為對應min heap內的位置
	/*
	因為從max對過去min有可能還有子節點
	所以看partner還有沒有子節點，有的話要再做判斷，取大的
	*/
	if (partner * 2 <= size)
	{
		partner *= 2;
		if (partner + 1 <= size&&d->arr[partner] < d->arr[partner + 1])
			partner++;
	}

	if (d->arr[partner] > temp)
	{
		/*
		比min heap對應的小:
		將max heap的空格填入min partner的數字
		將原先deap的最後一個元素插入min heap
		*/
		d->arr[p] = d->arr[partner];
		insertMinHeap(d, partner, temp);
	}
	else
		insertMaxHeap(d, p, temp);//將max heap的空格填入原先的最後一個

	return max;
}


int searchDeap(Deap* d, int num)
{
	int size = SIZE_TO_IDX(d->size), i;
	for (i = 2; i <= size; i++)
		if (num == d->arr[i])
			return i;

	return 0;
}
void printDeap(Deap* d)
{
	int size = SIZE_TO_IDX(d->size), i;
	for (i = 2; i <= size; i++)
		printf("%d ", d->arr[i]);
}
void destroyDeap(Deap *d)
{
	//free
	free(d->arr);
	free(d);
}
