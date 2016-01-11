#include<stdio.h>
#include"Deap.h"

int main()
{
	Deap* deap = createDeap(20);

	int i;
	do
	{
		printf("(1)insert (2)search (3)show (4)popMax (5)popMin (6)exit: ");
		scanf("%d", &i);

		if (i == 1)
		{
			int n;
			scanf("%d", &n);
			insertDeap(deap, n);
		}
		else if (i == 2)
		{
			int n, j;
			scanf("%d", &n);
			j = searchDeap(deap, n);
			if (j)
				printf("Search result: Yes(index is %d)\n", j);
			else
				printf("Search result: No\n");

		}
		else if (i == 3)
		{
			printDeap(deap);
			putchar('\n');
		}
		else if (i == 4)
			printf("%d\n", popMaxHeap(deap));
		else if (i == 5)
			printf("%d\n", popMinHeap(deap));

	} while (i != 6);

	destroyDeap(deap);

	return 0;

}
