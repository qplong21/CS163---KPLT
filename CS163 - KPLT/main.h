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

	TernarySearchTree();
	void deleteTree();
	void add2Tree(std::string keyword, std::string definition, bool importing = true);
	void editKeyword(TernaryTreeNode*& tem, std::string newDefinition);
	TernaryTreeNode* search4keyword(std::string keyword, bool normal = true);
	void import_slang();
	void import_emotional();
	void import_dictionary();
	int size;
	TernaryTreeNode* getRandomWord(bool normal = true, int i = 0);
	void guessRandomWord();
	void guessRandomDefinition();
	void addNewWordToDict();
	void deleteKeword(std::string keyword);
	TernaryTreeNode* getRoot();
private:
	TernaryTreeNode* root = nullptr;
	std::pair<std::string, std::string> wordAndDefinition[4]; //de lam guess game
};

