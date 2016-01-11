#include<stdio.h>
#include"queue.h"

void printElement(element ele);//callback function
int main()
{

	queue* Q = createQueue();
	int i;

	do
	{
		printf("(1)enQueue (2)deQueue (3)getElement (4)clearQueue (5)traverse (6)length (7)exit : ");
		scanf("%d", &i);

		if (i == 1)
		{
			element ele;
			int temp;
			scanf("%d", &temp);
			ele.val = temp;

			enQueue(Q, ele);
		}
		else if (i == 2)
			printf("%s\n", deQueue(Q) ? "success" : "fail");
		else if (i == 3)
			printf("%d\n", getElement(Q).val);
		else if (i == 4)
			clearQueue(Q);
		else if (i == 5)
		{
			traverseQueue(Q, printElement);
			putchar('\n');
		}
		else if(i == 6)
			printf("%d\n",getLength(Q));

	} while (i != 7);

	destroyQueue(Q);

	return 0;
}
void printElement(element ele)
{
	printf("%d ", ele.val);
}
