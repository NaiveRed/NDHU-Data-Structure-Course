#ifndef HASHTABLE_H
#define HASHTABLE_H
#define SLOT_SIZE 1
#define TABLE_SIZE 31

#include<stdbool.h>

typedef struct Data
{
	int key[SLOT_SIZE];

}data;

data* createTable();//return a hash table
int hash(int num);//hash function 
bool linear_insert(data *table, int num);//linear probing
int* searchTable(data *table,int num);//find num if exist 
void showTable(data *table);//print table 

#endif
