#include "main.h"
#include "functions.h"

int main()
{
	//srand(time(0)); //khoi tao random
	TernarySearchTree arr_of_tree;
	arr_of_tree.import_dictionary();
	//arr_of_tree.getRandomWord();
	arr_of_tree.guessRandomWord();
	arr_of_tree.deleteTree();
}
