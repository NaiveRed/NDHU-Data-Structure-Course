#include<stdio.h>
#include"stack.h"

void printEle(element ele);//is used for callback
int main()
{
	stack *s = createStack();
	
	int i=0;
	while (i != 7)
	{
		printf("(1)push (2)pop (3)showTop (4)clear (5)traverse (6)getSize (7)exit: ");
		scanf("%d", &i);

		if (i == 1)
		{
			int temp;
			element ele;
			scanf("%d", &temp);
			ele.val = temp;

			push(s, ele);
		}
		else if (i == 2)
			pop(s);
		else if (i == 3)
			printf("%d\n", getTop(s).val);
		else if (i == 4)
			clearStack(s);
		else if (i == 5)
		{
			traverseStack(s, printEle);
			putchar('\n');
		}
		else if (i == 6)
			printf("size: %d\n", getSize(s));
	}

	destroyStack(s);

	return 0;
}
void printEle(element ele)
{
	printf("%d ", ele.val);
}