#include "main.h"
#include "functions.h"
#include "Screen.h"
int main()
{
	header();
	system("pause");
	srand(time(NULL)); //khoi tao random//Tung dang test cai nay
	TernarySearchTree listOfTree[NUMofSET];
	createSet(listOfTree);//khoi tao

	listOfTree[2].search4keyword("Apple");
	listOfTree[2].addNewWordToDict();
	listOfTree[2].search4keyword("Apple");
	saveAllTree(listOfTree);
	for (int i = 0; i < 3; ++i)//xoa
	{
		listOfTree[i].deleteTree();
	}
}
