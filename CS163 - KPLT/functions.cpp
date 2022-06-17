#include "functions.h"
#include <iostream>
std::default_random_engine dre(std::chrono::steady_clock::now().time_since_epoch().count());
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
int getRandom(int lim)
{
	std::uniform_int_distribution<int> uid{ 0,lim };
	return uid(dre);
}