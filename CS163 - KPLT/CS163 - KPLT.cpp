#include "main.h"
#include "functions.h"

#define NUMofSET 3

int main()
{
	/*TernarySearchTree listOfTree[NUMofSET];
	createSet(listOfTree);
	for (int i = 0; i < 3; ++i)
	{
		listOfTree[i].deleteTree();
	}*/
	srand(time(NULL)); //khoi tao random//Tung dang test cai nay
	TernarySearchTree arr_of_tree;
	arr_of_tree.import_dictionary();
	arr_of_tree.guessRandomWord();
	arr_of_tree.deleteTree();
}
