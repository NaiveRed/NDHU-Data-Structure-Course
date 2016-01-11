#include <stdio.h>
#include"BinaryTree.h"

int main()
{
	int size;

	while (scanf("%d", &size) != EOF)
	{
		node_t *root = NULL;//init ¬° NULL 

		//input for each node
		while (size--)
		{
			int temp;
			scanf("%d", &temp);
			insert(&root, temp);
		}

		printf("min:%d\n", Min(root));
		printf("max:%d\n", Max(root));
		printf("inorder:");
		inorder(root);
		putchar('\n');
				
		//delete
		int rm;
		scanf("%d", &rm);	
		printf("after delete inorder:");
		root = removeNode(root, rm);
		inorder(root);
		printf("\nmin:%d\n", Min(root));
		printf("max:%d\n", Max(root));
		putchar('\n');
		
		destroyTree(root);
	}
	
	return 0;
}

