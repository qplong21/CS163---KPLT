#pragma once

#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>

#define NUMofSET 3

struct LinkedListNode {
	std::string str;
	LinkedListNode* next;
};

struct LinkedList {
	LinkedListNode* root;
	void insert(std::string str);
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
	TernaryTreeNode* root = nullptr;
	std::pair<std::string, std::string> wordAndDefinition[4]; //de lam guess game
};

