#include "Screen.h"
#include <string>
using namespace std;



void header() {
	system("cls");
	gotoxy(15, 0);
	std::cout << "Welcome to Dictionary";
	gotoxy(12, 1);
	std::cout << "Made by Group 4-KPLT-APCS21";
	gotoxy(0, 2);
	std::cout << "__________________________________________________";
	gotoxy(0, 4);
}

int convert(int choice) {
	if (choice == 27) return 0;
	return choice - 48;
}

int menuStart() {
	system("cls");
	header();
	std::cout << "0. Exit.\n";
	std::cout << "1. Search for a Definition of an English Word.\n";
	std::cout << "2. Search for a Definition of a slang.\n";
	std::cout << "3. Search for a Definition of an Emoji.\n";
	std::cout << "4. Guess the meaning of a word.\n";
	std::cout << "Option: ";
	int choice = _getch();
	return convert(choice);
}

void goodbye() {
	system("cls");
	header();
	std::cout << "Thanks for using our dictionary ^_^\n";
	std::cout << "See you later\n\n";
	system("pause");
}

void Input(string in) {
	if (in[0] >= 'a' && in[0] <= 'z') {
		in[0] = in[0] - 32;
	}
	for (int i = 1; in[i] != '\0'; i++) {
		if (in[i] >= 'A' && in[i] <= 'Z') {
			in[i] = in[i] + 32;
		}
	}
	return;
}