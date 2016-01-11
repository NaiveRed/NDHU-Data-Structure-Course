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
	//做dfs到正確的地方後，存下node
	if (!(*root))//如果為NULL,則create node 
	{
		node_t *tar = create();
		tar->tree_data = val;
		*root = tar;

		return true;
	}
	else if (val < (*root)->tree_data)//如果val小於node的data，就往left child移動 
		return insert(&((*root)->left), val);
	else if (val > (*root)->tree_data)//如果val大於node的data，就往right child移動
		return insert(&((*root)->right), val);
	else if (val == (*root)->tree_data)//相等不存入 
		return false;
}
node_t *search(node_t *root, int val)
{
	//做dfs,相等時就傳回node
	if (!root)
		return NULL;
	else if (val < root->tree_data)//如果val小於node的data，就往left child移動 
		search(root->left, val);
	else if (val > root->tree_data)//如果val大於node的data，就往right child移動
		search(root->right, val);
	else if (val == root->tree_data)//相等就傳回目前node 
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
	while (root)//直到left node為NULL，此時node即是min
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
	while (root)//直到right node為NULL，此時node即是max
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
node_t *findMin(node_t* root)//找出最小的，傳回node 
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
	//沒有用pointer to pointer去更改傳進去的root，所以要把return的root再assign回去
	if (!root)
		return root;
	else if (val < root->tree_data)//如果val小於node的data，就往left child移動  
		root->left = removeNode(root->left, val); 
	else if (val > root->tree_data)//如果val大於node的data，就往right child移動
		root->right = removeNode(root->right, val);
	else //找到val的位置後 
	{
		//no child
		if (!(root->left) && !(root->right))
		{
			//直接刪除node 
			free(root);
			root = NULL;
		}
		//one child
		else if (!(root->right))//右邊為NULL，將目前的 node = left child ，再刪除剛剛的node
		{
			node_t* temp = root;
			root = root->left;
			free(temp);
		}
		else if (!(root->left))//左邊為NULL，將目前的 node = right child ，再刪除剛剛的node
		{
			node_t* temp = root;
			root = root->right;
			free(temp);
		}
		//two children
		else
		{
			node_t* temp = findMin(root->right);//找右邊子樹中最小來取代目標 
			root->tree_data = temp->tree_data;
			root->right = removeNode(root->right, temp->tree_data);//把移上來的node，從原本的位置刪除，接著遞迴操作 
		}

	}

	return root;//回傳root

}
node_t *utilitySearch(node_t *root,int val)
{
	while(root)
	{	
		if(root->tree_data == val)//如果val已經在樹裡， retrun NULL
			return NULL;
		//回傳最後一個合適的位置(NULL前)，左或右在insert裡判斷 
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
		
		//向左向右複製
		clone->left = copy(tar->left);
		clone->right = copy(tar->right);
		clone->tree_data = tar->tree_data;
		
		return clone;
	}	
	
	return NULL;
}


