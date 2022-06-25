#include "main.h"
#include "functions.h"
#include "Screen.h"
int main()
{
	header();
	//system("pause");
	int choice = menuStart(); 
	while (choice != 4) {// Insert ham vao tung muc cua menu gium nha
		if (choice == 1) {// dich tu Tieng Anh

		}
		else if (choice == 2) {// dich slang

		}
		else {// dich emoji

		}
		choice = menuStart();
	}
	srand(time(NULL)); //khoi tao random//Tung dang test cai nay
	TernarySearchTree listOfTree[NUMofSET];
	createSet(listOfTree);//khoi tao

	saveAllTree(listOfTree);

	listOfTree[2].search4Definition("yellow fruit").display("yellow fruit");

	/*listOfTree[2].search4keyword("APPLE");*/

	for (int i = 0; i < 3; ++i)//xoa
	{
		listOfTree[i].deleteTree();
	}
}
