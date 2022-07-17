#include "main.h"
#include "functions.h"
#include "Screen.h"

//set menu 0 slang
//         1 emotion
//         2 dictionary
int main() { 
	SetColor(1);
	SetBGColor(15);
	header();
	system("pause");
	int choice = menuStart();
	while (choice != 0) {
		choice = menuStart();
	}
	goodbye();
	//srand(time(NULL)); //khoi tao random//Tung dang test cai nay
	//TernarySearchTree listOfTree[NUMofSET];
	//createSet(listOfTree);//khoi tao
	//int currentSet = 2;//mac dinh set se bang 2-dictionary 

	//listOfTree[1].guessRandomWord(true);

	///*listOfTree[currentSet].search4Definition("British").display("British");*/

	///*listOfTree[currentSet].search4keyword("APPLE");*/
	////saveAllTree(listOfTree);
	//for (int i = 0; i < 3; ++i)//xoa
	//{
	//	listOfTree[i].deleteTree();
	//}
}
