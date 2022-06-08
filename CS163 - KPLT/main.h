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
	TernaryTreeNode* root=nullptr;
	TernarySearchTree();
	void deleteTree();
	void add2Tree(std::string keyword,std::string definition);
	TernaryTreeNode* search4keyword(std::string keyword);
	void import_slang();
	void import_emotional();
	void import_dictionary();
};
