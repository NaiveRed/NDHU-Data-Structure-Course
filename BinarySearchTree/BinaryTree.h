#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include<stdbool.h>

//binary search tree

typedef struct node {
	struct node *left;
	struct node *right;
	int tree_data;
}node_t;

node_t *create();
node_t *search(node_t *, int);
node_t *copy(node_t *);

bool insert2(node_t **,int);//another way to insert
node_t *utilitySearch(node_t *, int);//used in insert2

bool insert(node_t **, int);//return false if fail
					
int Min(node_t *);//it will return 0 if empty!!
int Max(node_t *);//it will return 0 if empty!!
void inorder(node_t *);

node_t *findMin(node_t* root); //utility function for remove node
node_t *removeNode(node_t* root, int val);

void destroyTree(node_t* root);

#endif

