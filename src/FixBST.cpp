/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node
{
	struct node * left;
	int data;
	struct node *right;
};


// USING INORDER TRAVERSAL, Since it processes in ascending order comparing present data value with 
// previous data value, we can find both the misplaced values. propagating first misplaced value throughout
// recursion until second misplaced value founds and swapping gives the result..

void inorder_fix(struct node *root, int **prev, int **toswap1, int **toswap2)
{
	if (root != NULL)
	{
		inorder_fix(root->left, prev, toswap1, toswap2);
		if (**prev > root->data && *toswap1 == NULL)
		{
			*toswap1 = *prev;
			*toswap2 = &root->data;
		}
		else if (**prev > root->data && *toswap1 != NULL)
			*toswap2 = &root->data;
		*prev = &root->data;
		inorder_fix(root->right, prev, toswap1, toswap2);
	}
}


void fix_bst(struct node *root)
{
	int *prev = NULL, temp = -1;
	int *a = NULL, *b = NULL;
	if (root == NULL)
		return;
	prev = &temp;
	inorder_fix(root, &prev, &a, &b);
	temp = *a;
	*a = *b;
	*b = temp;

}
