#pragma once

#include "main.h"
#include <string.h>
#include <chrono>
#include <random>

void deletetree(TernaryTreeNode* root);

void createSet(TernarySearchTree* listOfTree);
int childOfNode(TernaryTreeNode* node);
void printTree(TernaryTreeNode* root, std::string str);