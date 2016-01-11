#include<stdio.h>
#include"DoublyLinkedList.h"

void print(element ele);//callback function for traverse
int main()
{
	duList* list = createDuList();

	int i;
	do
	{
		printf("(1)push_back (2)push_front (3)remove_back (4)remove_front \n(5)getBack (6)getFront (7)getElement (8)traverse (9)clear (10)exit:");
		scanf("%d", &i);

		if (i == 1)
		{
			element ele;
			int temp;
			scanf("%d", &temp);
			ele.val = temp;
			push_back(list, ele);
		}
		else if (i == 2)
		{
			element ele;
			int temp;
			scanf("%d", &temp);
			ele.val = temp;
			push_front(list, ele);
		}
		else if (i == 3)
			remove_back(list);
		else if (i == 4)
			remove_front(list);
		else if (i == 5)
			printf("%d\n", getBack(list).val);
		else if (i == 6)
			printf("%d\n", getFront(list).val);
		else if (i == 7)
		{
			int temp;
			scanf("%d", &temp);
			printf("%d\n", getElement(list, temp).val);
		}
		else if (i == 8)
		{
			traverse(list, 1,print);//1是正向,0是反向
			putchar('\n');
		}
		else if (i == 9)
			clearDuList(list);

	} while (i!=10);

	destroyDuList(list);

	return 0;
}
void print(element ele)
{
	printf("%d ", ele.val);
}