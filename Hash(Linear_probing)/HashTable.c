#include"HashTable.h"
#include<string.h>
#include<stdlib.h>

data* createTable()
{
	//allocate the memory
	data* table = (data*)malloc(sizeof(data)*TABLE_SIZE);

	int i, j;
	for (i = 0; i < TABLE_SIZE; i++)
		for (j = 0; j < SLOT_SIZE; j++)
			table[i].key[j] = 0;

	return table;

}
int hash(int num)
{
	return num % TABLE_SIZE;
}
bool linear_insert(data *table, int num)
{
	int i, hash_val;
	i = hash_val = hash(num);

	int slot;

	do
	{
		for (slot = 0; slot < SLOT_SIZE; slot++)//find each slot
		{
			if (table[i].key[slot])
			{
				if (table[i].key[slot] == num)
				{
					//已經存在
					return false;
				}
			}
			else
			{
				table[i].key[slot] = num;
				return true;
			}
		}

		i = (i + 1) % TABLE_SIZE;//linear probing

	} while (i != hash_val);

	return false;

}
int* searchTable(data *table, int num)
{
	int val = hash(num);
	int i = val;

	do
	{
		if (table[i].key[0] == num)
		{
			printf("index: %d\n", i);
			return &(table[i].key[0]);
		}
		else
			i = (i + 1) % TABLE_SIZE;
	} while (i != val);

	return NULL;
}
void showTable(data *table)
{
	int i, j;
	for (i = 0; i < TABLE_SIZE; i++)
	{
		printf("%d -> ", i);
		if (table[i].key[0])
			for (j = 0; j < SLOT_SIZE; j++)
				printf("%d ", table[i].key[j]);

		putchar('\n');
	}
}
