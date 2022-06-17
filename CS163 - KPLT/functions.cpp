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
default_random_engine dre(chrono::steady_clock::now().time_since_epoch().count());     // provide seed
int getRandom(int lim)
{
	uniform_int_distribution<int> uid{ 0,lim };   // help dre to generate nos from 0 to lim (lim included);
	return uid(dre);    // pass dre as an argument to uid to generate the random no
}