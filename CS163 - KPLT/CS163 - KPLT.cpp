#include "main.h"
#include "functions.h"

int main()
{
	srand(time(NULL)); //khoi tao random//Tung dang test cai nay
	TernarySearchTree listOfTree[NUMofSET];
	createSet(listOfTree);//khoi tao

	saveAllTree(listOfTree);


	listOfTree[2].search4keyword("Apple");
	listOfTree[2].addNewWordToDict();
	listOfTree[2].search4keyword("Apple");

	for (int i = 0; i < 3; ++i)//xoa
	{
		listOfTree[i].deleteTree();
	}
}
