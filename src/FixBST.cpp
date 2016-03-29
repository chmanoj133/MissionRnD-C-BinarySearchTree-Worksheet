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

void inorder_fix(struct node *root, int **prev, int **toswap1, int **toswap2, int *action)
{
	if (root != NULL)
	{
		inorder_fix(root->left, prev, toswap1, toswap2, action);
		if (**prev > root->data && *toswap1 == NULL)
		{
			*toswap1 = *prev;
			*toswap2 = &root->data;
			*action = 1;
		}
		else if (**prev > root->data && *toswap1 != NULL)
		{
			*toswap2 = &root->data;
			int temp = **toswap1;
			**toswap1 = **toswap2;
			**toswap2 = temp;
			*action = 2;
		}
		*prev = &root->data;
		inorder_fix(root->right, prev, toswap1, toswap2, action);
	}
}


void fix_bst(struct node *root)
{
	int *prev = NULL, temp = -1;
	int action = 0;
	int *a = NULL, *b = NULL;
	prev = &temp;
	inorder_fix(root, &prev, &a, &b, &action);
	if (action == 1)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}

}
