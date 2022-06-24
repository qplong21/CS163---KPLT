#include <iostream>
#include "console.h"

void header() {
	SetBGColor(15);
	system("cls");
	SetColor(1);
	gotoxy(15, 0);
	std::cout << "Welcome to Dictionary";
	gotoxy(12, 1);
	std::cout << "Made by Group 4-KPLT-APCS21";
	gotoxy(0, 2);
	std::cout << "__________________________________________________";
	gotoxy(0, 4);
	SetColor(0);
}
