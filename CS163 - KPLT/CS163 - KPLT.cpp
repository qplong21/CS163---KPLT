#include "main.h"
#include "functions.h"

#define NUMofSET 3

int main()
{
<<<<<<< Updated upstream
	srand(time(NULL)); //khoi tao random
	TernarySearchTree arr_of_tree;
	arr_of_tree.import_dictionary();
	arr_of_tree.guessRandomWord();
	arr_of_tree.deleteTree();
=======
	TernarySearchTree listOfTree[NUMofSET];
	createSet(listOfTree);
	for (int i = 0;i < 3;++i)
	{
		listOfTree[i].deleteTree();
	}
	
>>>>>>> Stashed changes
}
