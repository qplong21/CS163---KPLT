#include "main.h"
#include "functions.h"

int main()
{
	srand(time(NULL)); //khoi tao random//Tung dang test cai nay
	TernarySearchTree listOfTree[NUMofSET];
	createSet(listOfTree);//khoi tao

	saveAllTree(listOfTree);


	listOfTree[2].inorderTraversal();

	for (int i = 0; i < 3; ++i)//xoa
	{
		listOfTree[i].deleteTree();
	}
}
