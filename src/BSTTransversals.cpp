/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


void inorder_wrap(struct node *root, int *arr, int *i)
{
	if (root != NULL)
	{
		inorder_wrap(root->left, arr, i);
		arr[*i] = root->data;
		*i = *i + 1;
		inorder_wrap(root->right, arr, i);
	}
}

void inorder(struct node *root, int *arr)
{
	int i = 0;
	if (arr != NULL)
		inorder_wrap(root, arr, &i);
}

void preorder_wrap(struct node *root, int *arr, int *i)
{
	if (root != NULL)
	{
		arr[*i] = root->data;
		(*i)++;
		preorder_wrap(root->left, arr, i);
		preorder_wrap(root->right, arr, i);
	}
}
void preorder(struct node *root, int *arr)
{
	int i = 0;
	if (arr != NULL)
		preorder_wrap(root, arr, &i);
}

void postorder_wrap(struct node *root, int *arr, int *i)
{
	if (root != NULL)
	{
		postorder_wrap(root->left, arr, i);
		postorder_wrap(root->right, arr, i);
		arr[*i] = root->data;
		(*i)++;
	}
}
void postorder(struct node *root, int *arr)
{
	int i = 0;
	if (arr != NULL)
		postorder_wrap(root, arr, &i);
}

