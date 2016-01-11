#include<stdio.h>
#include<stdlib.h>
#include"HashTable.h"

int main(){

	data *ht = createTable();
	int cmd;

	printf("(1)insert (2)search (3)show (4)exit: ");
	while (scanf("%d", &cmd) && cmd != 4)
	{
		if (cmd == 1)
		{
			int n;
			scanf("%d", &n);
			if (linear_insert(ht, n))
				puts("ok");
			else 
				puts("failed");

		}
		else if (cmd == 2)
		{
			int n;
			scanf("%d", &n);

			int *ptr = searchTable(ht, n);
			if (ptr)
				printf("%d\n", *ptr);
		}
		else if (cmd == 3)
			showTable(ht);
	
		printf("(1)insert (2)search (3)show (4)exit: ");
	}

	free(ht);

	return 0;
}
