#include "main.h"
#include "functions.h"

#define NUMofSET 3

int main()
{
	/*TernarySearchTree listOfTree[NUMofSET];//Long dang test cai nay
	createSet(listOfTree);
	for (int i = 0; i < 3; ++i)
	{
		listOfTree[i].deleteTree();
	}*/
	srand(time(NULL)); //khoi tao random//Tung dang test cai nay
	TernarySearchTree arr_of_tree;
	arr_of_tree.import_dictionary();
	std::string s;
	do {
		std::getline(std::cin, s);
		arr_of_tree.search4keyword(s);
	} while (s != "");
	arr_of_tree.deleteTree();
}
