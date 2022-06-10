#include "functions.h"
#include <iostream>

using namespace std;

void deletetree(TernaryTreeNode *root)
{
	if (!root)
		return;
	deletetree(root->left);
	deletetree(root->mid);
	deletetree(root->right);
	delete root->definition;
	delete root;
}
void getRandomWord(TernarySearchTree tree)
{

}