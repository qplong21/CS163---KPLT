#pragma once

#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>

#define NUMofSET 3

struct WordAndDef {
	std::string word;
	std::string definition;
};

struct LinkedListNode {
	WordAndDef wad;
	LinkedListNode* next;
};

struct LinkedList {
	LinkedListNode* root = nullptr;
	void insert(WordAndDef wad);
	void display();
};

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
	void import_dictionary(int index, bool forReset = false);
	int size;
	TernaryTreeNode* getRandomWord(bool normal = true, int i = 0);
	void guessRandomWord();
	void guessRandomDefinition();
	void addNewWordToDict();
	void deleteKeword(std::string keyword);
	TernaryTreeNode* getRoot();
	void inorderTraversal();
	LinkedList search4Definition(std::string definition);
private:
	void inorderTraversalAux(TernaryTreeNode* node, std::string currentStr);
	void inorderTraversalForSearch(TernaryTreeNode* node, std::string currentStr, std::string definition, LinkedList& ll);
	TernaryTreeNode* root = nullptr;
	std::pair<std::string, std::string> wordAndDefinition[4]; //de lam guess game
};

