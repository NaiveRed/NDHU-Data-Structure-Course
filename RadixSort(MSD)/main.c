#include"RadixSort.h"
#include<stdio.h>
#include<stdlib.h>
#include"queue.h"
#define MAX_DIGIT 3

int main(){

	queue* sort = createQueue();
	queue* num = createQueue();

	int  temp, length = 0;
	element ele;

	//input
	while (scanf("%d", &temp) != EOF)
	{
		ele.val = temp;
		enQueue(num, ele);
		length++;
	}

	int i, n = 1;
	for (i = 1; i < MAX_DIGIT; i++)
		n *= 10;

	radixSortByMSD(sort, num, n);//sort

	//輸出大到小
	for (i = 0; i < length; i++)
	{
		printf("%d ", getElement(sort));
		deQueue(sort);
	}

	//destroy queue
	destroyQueue(sort);
	destroyQueue(num);

	putchar('\n');
	system("pause");

	return 0;
}