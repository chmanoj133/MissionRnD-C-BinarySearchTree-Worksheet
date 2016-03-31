/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node
{
	struct node * left;
	int data;
	struct node *right;
};


int closest_distance_down(struct node *root)
{
	struct store
	{
		struct node *root;
		int level;
	};

	struct store *queue = (struct store*)malloc(sizeof(struct store));
	int front = 0, rear = 1, next_len = 2;

	queue[0].root = root;
	queue[0].level = 0;

	while (1)
	{
		if (queue[front].root->left != NULL)
		{
			queue = (struct store*)realloc(queue, sizeof(struct store)*next_len);
			next_len++;
			queue[rear].level = queue[front].level + 1;
			queue[rear].root = queue[front].root->left;
			rear++;
		}
		if (queue[front].root->right != NULL)
		{
			queue = (struct store*)realloc(queue, sizeof(struct store)*next_len);
			next_len++;
			queue[rear].level = queue[front].level + 1;
			queue[rear].root = queue[front].root->right;
			rear++;
		}
		if (queue[front].root->left == NULL && queue[front].root->right == NULL)
		{
			return queue[front].level;
		}

		front++;
		if (front >= rear)
			break;
	}
	return 0;
}

int get_distance_btw_two_nodes(struct node *root, struct node *sub_node)
{
	int distance = 0;
	
	while (1)
	{
		if (root->data == sub_node->data)
			break;
		if (sub_node->data > root->data)
			root = root->right;
		else
			root = root->left;
		distance++;
	}
	return distance;
}

int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL)
		return -1;
	if (temp == NULL)
		return -1;
	if (temp->left == NULL && temp->right == NULL)
		return 1;

	int distance = closest_distance_down(temp);
	int temp_dist;

	while (1)
	{
		if (root->data == temp->data)
		{
			return distance;
		}
		if (temp->data < root->data)
		{
			temp_dist = closest_distance_down(root->right) + 1;
			temp_dist = temp_dist + get_distance_btw_two_nodes(root, temp);
			if (temp_dist < distance)
				distance = temp_dist;
			root = root->left;
		}
		else
		{
			temp_dist = closest_distance_down(root->left) + 1;
			temp_dist = temp_dist + get_distance_btw_two_nodes(root, temp);
			if (temp_dist < distance)
				distance = temp_dist;
			root = root->right;
		}
	}

}