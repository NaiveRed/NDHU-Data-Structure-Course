#include<stdio.h>
#include"Heap.h"
#define SIZE 10

void print(element ele);//callback for traverse
int main()
{
	heap *h = createHeap(SIZE);//size is 10
	int i, type;
	printf("(1)max heap (2)min heap:");
	scanf("%d", &type);

	do{
		printf("(1)insert  (2)pop  (3)show  (4)clear  (5)exit: ");

		scanf("%d", &i);

		if (i == 1)
		{
			int temp;
			element e;
			scanf("%d", &temp);
			e.val = temp;
			if (type == 1)
				insertMaxHeap(h, e);
			else if (type == 2)
				insertMinHeap(h, e);
		}
		else if (i == 2)
			printf("%d\n", type == 1 ? popMaxHeap(h).val : popMinHeap(h).val);
		else if (i == 3)
		{
			traverse(h, print);
			putchar('\n');
		}
		else if (i == 4)
			clearHeap(h);

	} while (i != 5);

	destroyHeap(h);

	return 0;
}
void print(element ele)
{
	printf("%d ", ele.val);
}
