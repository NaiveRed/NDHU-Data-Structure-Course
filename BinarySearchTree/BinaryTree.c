#include"BinaryTree.h"
#include<stdlib.h>
#include<stdbool.h>

node_t *create()
{
	//init
	node_t *n = (node_t*)malloc(sizeof(node_t));
	n->left = NULL;
	n->right = NULL;

	return n;
}
bool insert(node_t **root, int val)
{
	//��dfs�쥿�T���a���A�s�Unode
	if (!(*root))//�p�G��NULL,�hcreate node 
	{
		node_t *tar = create();
		tar->tree_data = val;
		*root = tar;

		return true;
	}
	else if (val < (*root)->tree_data)//�p�Gval�p��node��data�A�N��left child���� 
		return insert(&((*root)->left), val);
	else if (val > (*root)->tree_data)//�p�Gval�j��node��data�A�N��right child����
		return insert(&((*root)->right), val);
	else if (val == (*root)->tree_data)//�۵����s�J 
		return false;
}
node_t *search(node_t *root, int val)
{
	//��dfs,�۵��ɴN�Ǧ^node
	if (!root)
		return NULL;
	else if (val < root->tree_data)//�p�Gval�p��node��data�A�N��left child���� 
		search(root->left, val);
	else if (val > root->tree_data)//�p�Gval�j��node��data�A�N��right child����
		search(root->right, val);
	else if (val == root->tree_data)//�۵��N�Ǧ^�ثenode 
		return root;
}
void inorder(node_t *root)//inorder
{
	if (root)
	{
		inorder(root->left);
		printf("%d ", root->tree_data);
		inorder(root->right);
	}

}
int Min(node_t *root)
{
	while (root)//����left node��NULL�A����node�Y�Omin
	{
		if (root->left)
			root = root->left;
		else
			return root->tree_data;
	}

	return NULL;

}
int Max(node_t *root)
{
	while (root)//����right node��NULL�A����node�Y�Omax
	{
		if (root->right)
			root = root->right;
		else
			return root->tree_data;
	}

	return NULL;

}
void destroyTree(node_t* root)
{
	//free all node
	if (root)
	{
		destroyTree(root->left);
		destroyTree(root->right);
		free(root);
	}
}
node_t *findMin(node_t* root)//��X�̤p���A�Ǧ^node 
{
	while (root)
	{
		if (root->left)
			root = root->left;
		else
			return root;
	}

	return NULL;
}
node_t *removeNode(node_t* root, int val)
{
	//�S����pointer to pointer�h���Ƕi�h��root�A�ҥH�n��return��root�Aassign�^�h
	if (!root)
		return root;
	else if (val < root->tree_data)//�p�Gval�p��node��data�A�N��left child����  
		root->left = removeNode(root->left, val); 
	else if (val > root->tree_data)//�p�Gval�j��node��data�A�N��right child����
		root->right = removeNode(root->right, val);
	else //���val����m�� 
	{
		//no child
		if (!(root->left) && !(root->right))
		{
			//�����R��node 
			free(root);
			root = NULL;
		}
		//one child
		else if (!(root->right))//�k�䬰NULL�A�N�ثe�� node = left child �A�A�R����誺node
		{
			node_t* temp = root;
			root = root->left;
			free(temp);
		}
		else if (!(root->left))//���䬰NULL�A�N�ثe�� node = right child �A�A�R����誺node
		{
			node_t* temp = root;
			root = root->right;
			free(temp);
		}
		//two children
		else
		{
			node_t* temp = findMin(root->right);//��k��l�𤤳̤p�Ө��N�ؼ� 
			root->tree_data = temp->tree_data;
			root->right = removeNode(root->right, temp->tree_data);//�Ⲿ�W�Ӫ�node�A�q�쥻����m�R���A���ۻ��j�ާ@ 
		}

	}

	return root;//�^��root

}
node_t *utilitySearch(node_t *root,int val)
{
	while(root)
	{	
		if(root->tree_data == val)//�p�Gval�w�g�b��̡A retrun NULL
			return NULL;
		//�^�ǳ̫�@�ӦX�A����m(NULL�e)�A���Υk�binsert�̧P�_ 
		else if(val < root->tree_data)
			{
				if(root->left)
					root = root->left;
				else 
					return root;
			}
		else
			{
				if(root->right)
					root = root->right;
				else 
					return root;
			}
	}
	
	return NULL;//the tree is empty
}

bool insert2(node_t **root,int val)
{
	node_t *temp = utilitySearch((*root),val);
	
	if(!(*root)||temp)//val is in the tree or the tree is empty 
	{
		node_t *ptr = create();
		ptr->tree_data = val;
		
		if(*root)
			{
			if(val > temp->tree_data)
				temp->right = ptr;
			else 
				temp->left = ptr;
			} 
		else 
			(*root) = ptr;
		
		return true;
	}
	
	return false;
}
node_t *copy(node_t *tar)
{
	if(tar)
	{
		node_t *clone = create();
		
		//�V���V�k�ƻs
		clone->left = copy(tar->left);
		clone->right = copy(tar->right);
		clone->tree_data = tar->tree_data;
		
		return clone;
	}	
	
	return NULL;
}


