#ifndef AVLTREE_H
#define AVLTREE_H

typedef struct element
{
	int key;

}Element;

typedef struct node
{
	Element data;

	//tree level
	int height;//empty is -1

	struct node* left_child;
	struct node* right_child;

}Node;

Node* getNewNode(Element data);
int getHigherLevel(Node* left,Node* right);//get the higher height of two subtrees
int getBalanceFactor(Node* n);

Node* leftRotate(Node *root);
Node* rightRotate(Node *root);
Node* insert(Node* root, Element data);

void inorder(Node* root);
void destroyTree(Node *root);

#endif