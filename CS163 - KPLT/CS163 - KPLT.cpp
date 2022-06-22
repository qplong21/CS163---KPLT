#include "main.h"
#include "functions.h"

#define NUMofSET 3

int main()
{
	srand(time(NULL)); //khoi tao random//Tung dang test cai nay
	TernarySearchTree listOfTree[NUMofSET];
	createSet(listOfTree);//khoi tao


	//std::string s;//thu search
	//do {
	//	std::getline(std::cin, s);
	//	listOfTree[2].search4keyword(s);//list of tree [2] la dictionary
	//} while (s != "");

	/*std::string str = "";//Long dan test cai nay
	printTree(listOfTree[2].getRoot(), str);*/

	for (int i = 0; i < 3; ++i)//xoa
	{
		listOfTree[i].deleteTree();
	}
}
