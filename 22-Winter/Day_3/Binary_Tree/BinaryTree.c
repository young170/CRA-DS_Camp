#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode* make_btree_node(void)
{
    BTreeNode *new_node = (BTreeNode*) malloc(sizeof(BTreeNode));
    new_node->left = new_node->right = NULL;	// make it a terminal node

    return new_node;
}

BTData get_data(BTreeNode* bt)
{
    return bt->data;
}

void set_data(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

BTreeNode* get_left_sub_tree(BTreeNode* bt)
{
	return bt->left;
}
BTreeNode* get_right_sub_tree(BTreeNode* bt)
{
	return bt->right;
}

void make_left_sub_tree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left != NULL)		//  check for memory leak
		free(main->left);
	main->left = sub;
}

void make_riht_sub_tree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != NULL)
		free(main->right);
	main->right = sub;
}