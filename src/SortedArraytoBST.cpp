/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node
{
	struct node * left;
	int data;
	struct node *right;
};

struct node* add_node(int data)
{
	struct node *root = (struct node*)malloc(sizeof(struct node));
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;
}

struct node* convert_array_to_bst_wrapper(int *arr, int low, int high)
{
	struct node* root;
	int mid = (low + high) / 2;

	if (low <= high)
	{
		root = add_node(arr[mid]);
		root->left = convert_array_to_bst_wrapper(arr, low, mid - 1);
		root->right = convert_array_to_bst_wrapper(arr, mid + 1, high);
		return root;
	}
	else
		return NULL;
}

struct node * convert_array_to_bst(int *arr, int len)
{
	if (arr == NULL)
		return NULL;
	return convert_array_to_bst_wrapper(arr, 0, len - 1);
}

