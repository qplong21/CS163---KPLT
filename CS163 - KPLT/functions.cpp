#include "functions.h"
#include <iostream>

void deletetree(TernaryTreeNode* root)
{
	if (!root)
		return;
	deletetree(root->left);
	deletetree(root->mid);
	deletetree(root->right);
	delete root->definition;
	delete root;
}

void createSet(TernarySearchTree* listOfTree)
{
	listOfTree[0].import_slang();
	listOfTree[1].import_emotional();
	listOfTree[2].import_dictionary();
}

int childOfNode(TernaryTreeNode* node)//return number of child
{
	int i = 0;
	if (node->left)
		++i;
	if (node->mid)
		++i;
	if (node->right)
		++i;
	return i;
}