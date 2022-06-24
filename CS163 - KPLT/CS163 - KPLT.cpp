#include "main.h"
#include "functions.h"
#include "Screen.h"
int main()
{
	header();
	//system("pause");
	srand(time(NULL)); //khoi tao random//Tung dang test cai nay
	TernarySearchTree listOfTree[NUMofSET];
	createSet(listOfTree);//khoi tao

	saveAllTree(listOfTree);

	std::string in;
	do {
		std::getline(std::cin, in);
	} while (in.length() < 3);
	listOfTree[2].search4Definition(in).display();

	for (int i = 0; i < 3; ++i)//xoa
	{
		listOfTree[i].deleteTree();
	}
}
