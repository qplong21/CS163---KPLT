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
	
	for (int i = 0; i < 3; ++i)//xoa
	{
		listOfTree[i].deleteTree();
	}
}
