#include <iostream>
#include "console.h"
#include <string>

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

int convert(std::string str) {
	int t = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 48 && str[i] <= 57) {
			t = t * 10 + (str[i] - 48);
		}
		else
			return -1;
	}
	return t;
}

int menuStart() {
	std::cout << "1. Search for a Definition of an English Word.\n";
	std::cout << "2. Search for a Definition of a slang.\n";
	std::cout << "3. Search for a Definition of an Emoji.\n";
	std::cout << "4. Exit out of system.\n";
	std::cout << "Option: ";
	std::string input;
	std::getline(std::cin, input);
	int val = convert(input);
	while (val <= 0 && val >= 5) {
		std::cout << "Invalid value. Try again!\n";
		std::cout << "Option: ";
		std::getline(std::cin, input);
		val = convert(input);
	}
	system("cls");
	header();
	return val;
}