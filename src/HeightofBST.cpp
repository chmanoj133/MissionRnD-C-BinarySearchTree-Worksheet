/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

// get_height implemented here in two methods
// 1. Using queue -> level traversal (non-recursive)
// 2. Using post-order traversal (recursive)

int get_height(struct node *root)
{
	// explanation: In level traversal, last element in queue would the last node of largest path in BST
	// traversing from that node to root, counting each node is our height
	struct store
	{
		struct node *child;
		struct node *parent;
	};
	if (root == NULL)
		return 0;

	struct store *queue = (struct store*)malloc(sizeof(struct store));
	struct node *parent;
	queue[0].child = root;
	queue[0].parent = NULL;

	int front = 0, rear = 1, i, height = 1, next_len = 2;

	while (1)
	{
		if (queue[front].child->left != NULL) 
		{
			queue = (struct store*)realloc(queue, sizeof(struct store) * next_len);
			queue[rear].child = queue[front].child->left;
			queue[rear].parent = queue[front].child;
			next_len++;
			rear++;
		}
		if (queue[front].child->right != NULL)
		{
			queue = (struct store*)realloc(queue, sizeof(struct store) * next_len);
			queue[rear].child = queue[front].child->right;
			queue[rear].parent = queue[front].child;
			rear++;
			next_len++;
		}
		front++;

		if (front >= rear)
			break;
	}

	parent = queue[rear - 1].parent;
	for (i = rear - 1; i >= 0; i--)
	{
		if (queue[i].child == parent)
		{
			parent = queue[i].parent;
			height++;
		}
	}
	return height;
}

/*
int get_height(struct node* root)
{
	int left_height, right_height;
	if (root == NULL)
		return 0;
	else
	{
		left_height = get_height(root->left);
		right_height = get_height(root->right);

		if (left_height > right_height)
			return left_height + 1;
		else
			return right_height + 1;
	}
}

*/

void sum_of_tree(struct node *root, int *sum)
{
	if (root != NULL)
	{
		sum_of_tree(root->left, sum);
		*sum = *sum + root->data;
		sum_of_tree(root->right, sum);
	}
}

int get_left_subtree_sum(struct node *root)
{
	int sum = 0;
	if (root != NULL)
		sum_of_tree(root->left, &sum);
	return sum;
}

int get_right_subtree_sum(struct node *root)
{
	int sum = 0;
	if (root != NULL)
		sum_of_tree(root->right, &sum);
	return sum;
}

