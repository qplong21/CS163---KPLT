#include "main.h"
#include "functions.h"
#include "Screen.h"

//set menu 0 slang
//         1 emotion
//         2 dictionary
int main()
{
	header();


	//system("pause");
	//int choice = menuStart();//Phuc dang lam cai nay 
	//while (choice != 4) {// Insert ham vao tung muc cua menu gium nha
	//	if (choice == 1) {// dich tu Tieng Anh

	//	}
	//	else if (choice == 2) {// dich slang

	//	}
	//	else {// dich emoji

	//	}
	//	choice = menuStart();
	//}
	srand(time(NULL)); //khoi tao random//Tung dang test cai nay
	TernarySearchTree listOfTree[NUMofSET];
	createSet(listOfTree);//khoi tao
	int currentSet = 2;//mac dinh set se bang 2-dictionary 

	listOfTree[1].guessRandomWord(true);

	/*listOfTree[currentSet].search4Definition("British").display("British");*/

	/*listOfTree[currentSet].search4keyword("APPLE");*/
	//saveAllTree(listOfTree);
	for (int i = 0; i < 3; ++i)//xoa
	{
		listOfTree[i].deleteTree();
	}
}
