#include"AVLTree.h"
#include<stdlib.h>
#include<stdio.h>

Node* getNewNode(Element data)
{
	Node* n = (Node*)malloc(sizeof*n);
	n->data = data;
	n->right_child = n->left_child = NULL;
	n->height = 0;//empty is -1

	return n;
}
int getHigherLevel(Node* left, Node* right)
{
	if (!left&&!right)
		return -1;

	if (!left)
		return right->height;

	if (!right)
		return left->height;

	return left->height > right->height ? left->height : right->height;
}
int getBalanceFactor(Node* n)
{
	if (!n)
		return 0;

	//no child, -1 - (-1) = 0
	if (!n->left_child&&!n->right_child)
		return 0;

	//left child is empty, so is -1
	if (!n->left_child)
		return -1 - n->right_child->height;

	//right child is empty, so is -1, x - (-1) = x + 1
	if (!n->right_child)
		return  n->left_child->height + 1;

	//left height - right height
	return n->left_child->height - n->right_child->height;
}
Node* leftRotate(Node *root)
{
	Node *right = root->right_child;

	//rotate node
	root->right_child = right->left_child;
	right->left_child = root;

	//update height
	root->height = getHigherLevel(root->left_child, root->right_child) + 1;
	right->height = getHigherLevel(right->left_child, right->right_child) + 1;

	//原本的位置變為原本root->right
	return right;
}
Node* rightRotate(Node *root)
{
	Node* left = root->left_child;

	//rotate node
	root->left_child = left->right_child;
	left->right_child = root;

	//update height
	root->height = getHigherLevel(root->left_child, root->right_child) + 1;
	left->height = getHigherLevel(left->left_child, left->right_child) + 1;

	//原本的位置變為原本root->left
	return left;
}
Node* insert(Node* root, Element ele)
{
	if (!root)
		return getNewNode(ele);
	else if (ele.key > root->data.key)
		root->right_child = insert(root->right_child, ele);
	else if (ele.key < root->data.key)
		root->left_child = insert(root->left_child, ele);
	else//already in tree
		return root;

	//update the height
	root->height = getHigherLevel(root->right_child, root->left_child) + 1;

	//balance factor
	int bf = getBalanceFactor(root);


	//Left
	if (bf > 1)
	{
		if (ele.key < root->left_child->data.key)//Left,outside
			return rightRotate(root);
		else if (ele.key > root->left_child->data.key)//Right,inside
		{
			root->left_child = leftRotate(root->left_child);
			return rightRotate(root);
		}
	}
	//Right
	else if (bf < -1)
	{
		if (ele.key > root->right_child->data.key)//Right,outside
			return leftRotate(root);
		else if (ele.key < root->right_child->data.key)//Left,inside
		{
			root->right_child = rightRotate(root->right_child);
			return leftRotate(root);
		}
	}

	//balance,unchange
	return root;
}
void inorder(Node* root)
{
	if (!root)
		return;

	inorder(root->left_child);
	printf("%d ", root->data.key);
	inorder(root->right_child);
}
void destroyTree(Node *root)
{
	if (root)
	{
        //free
		destroyTree(root->left_child);
		destroyTree(root->right_child);
		free(root);
	}
}
