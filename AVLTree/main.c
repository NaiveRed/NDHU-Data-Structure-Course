#include<stdio.h>
#include<stdlib.h>
#include"AVLTree.h"

int main()
{
	int num;
	Element ele;
	Node *root = NULL;

	while (scanf("%d", &num) != EOF)
	{
		ele.key = num;
		root = insert(root, ele);
	}
	
    inorder(root);
	putchar('\n');

	//free
	destroyTree(root);

    system("pause");
	return 0;
}
