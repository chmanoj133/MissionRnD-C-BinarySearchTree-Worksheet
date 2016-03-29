/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


int* BSTRighttoLeftRows(struct node* root)
{
	int front = 0, rear = 1, next_len = 2, i;
	struct node **queue = (struct node**)malloc(sizeof(struct node*));
	int *arr;
	queue[0] = root;

	if (root == NULL)
		return NULL;

	while (1)
	{
		if (queue[front]->right != NULL)
		{
			queue = (struct node**)realloc(queue, sizeof(struct node*) * next_len);
			queue[rear] = queue[front]->right;
			rear++;
			next_len++;
		}

		if (queue[front]->left != NULL)
		{
			queue = (struct node**)realloc(queue, sizeof(struct node*) * next_len);
			queue[rear] = queue[front]->left;
			next_len++;
			rear++;
		}
		front++;

		if (front >= rear)
			break;
	}

	arr = (int *)malloc(sizeof(int)*rear);

	for (i = 0; i < next_len - 1; i++)
		arr[i] = queue[i]->data;

    return arr;
}
