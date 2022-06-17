#pragma once

#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <vector>

struct TernaryTreeNode
{
	char ch;
	TernaryTreeNode* left = nullptr, * mid = nullptr, * right = nullptr;
	std::string* definition = nullptr;
};

class TernarySearchTree
{
public:
	TernaryTreeNode* root = nullptr;
	TernarySearchTree();
	void deleteTree();
	void add2Tree(std::string keyword, std::string definition);
	TernaryTreeNode* search4keyword(std::string keyword, bool normal = true);
	void import_slang();
	void import_emotional();
	void import_dictionary();
	int size;
	TernaryTreeNode* getRandomWord(bool normal = true, int i = 0);
	void guessRandomWord();
private:
	std::pair<std::string, std::string> wordAndDefinition[4]; //de lam guess game
};

