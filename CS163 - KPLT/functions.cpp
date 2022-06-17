#include "functions.h"
#include <iostream>

using namespace std;

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