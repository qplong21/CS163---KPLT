#include "main.h"
#include "functions.h"

Node *listOfWords = nullptr;

void insertToLL(Node *&root, std::string word)
{
	Node *insert = new Node;
	insert->word = word;
	if (!root)
	{
		root = insert;
		return;
	}
	Node *current = root;
	while (current->next)
		current = current->next;
	current->next = insert;
}

std::string randomWord(Node *root, int num)
{
	Node *current = root;
	for (int i = 0; i < num; i++)
	{
		current = current->next;
	}
	return current->word;
}

TernarySearchTree::TernarySearchTree()
{
	root = new TernaryTreeNode;
	root->ch = 'n';
	root->definition = new std::string;
	*root->definition = "The letter N";
}

void TernarySearchTree::deleteTree()
{
	deletetree(this->root);
	this->root = nullptr;
}

void TernarySearchTree::add2Tree(std::string keyword, std::string definition)
{
	if (!this->root)
	{
		this->root = new TernaryTreeNode;
		this->root->ch = 'n';
		this->root->definition = new std::string;
		*this->root->definition = "The letter N";
	}
	TernaryTreeNode *tem = this->root;
	for (int i = 0; i < keyword.length(); ++i)
	{
		if (tem->ch == keyword[i]) // go mid
		{
			if (tem->mid)
			{
				tem = tem->mid;
			}
			else
			{
				if (i == keyword.length() - 1)
				{
					break;
				}
				else
				{
					tem->mid = new TernaryTreeNode;
					tem = tem->mid;
					tem->ch = keyword[i + 1];
				}
			}
			continue;
		}
		if (tem->ch < keyword[i]) // go right;
		{
			if (tem->right)
			{
				tem = tem->right;
			}
			else
			{
				tem->right = new TernaryTreeNode;
				tem = tem->right;
				tem->ch = keyword[i];
			}
			--i;
			continue;
		}
		if (tem->ch > keyword[i]) // go left
		{
			if (tem->left)
			{
				tem = tem->left;
			}
			else
			{
				tem->left = new TernaryTreeNode;
				tem = tem->left;
				tem->ch = keyword[i];
			}
			--i;
			continue;
		}
	}
	tem->definition = new std::string;
	*tem->definition = definition;
	this->size++; // tang phan so tu cua cay
	insertToLL(listOfWords, keyword);
}

TernaryTreeNode *TernarySearchTree::search4keyword(std::string keyword)
{
	// those line with "//" at the end is for debug
	// chinh cho viet hoa thuong search van duoc
	TernaryTreeNode *tem = this->root;
	// int count = 0;//
	for (int i = 0; i < keyword.length(); ++i)
	{
		if (tem == nullptr)
		{
			std::cout << "Not found\n";
			// std::cout << "Pass over " << count << " nodes\n";//
			return tem;
		}
		//++count;//
		// std::cout << tem->ch;//
		if (tem->ch == keyword[i])
		{
			if (i == keyword.length() - 1)
			{
				break;
			}
			else
			{
				tem = tem->mid;
				continue;
			}
		}
		if (tem->ch > keyword[i]) // go left
		{
			tem = tem->left;
			--i;
			continue;
		}
		if (tem->ch < keyword[i]) // go right
		{
			tem = tem->right;
			--i;
			continue;
		}
	}
	if (tem->definition)
	{
		std::cout << *tem->definition << "\n";
	}
	else
		std::cout << "Not found\n";
	// std::cout << "Pass over " << count << " nodes\n";//
	return tem;
}

TernaryTreeNode *TernarySearchTree::searchByNum(int num)
{
	return search4keyword(randomWord(listOfWords, num));
} // dung khi random

void TernarySearchTree::import_slang()
{
	std::ifstream fin("Library\\slang.txt");
	std::string keyword; // processing keyword and def
	std::string input_str;
	while (!fin.eof())
	{
		std::getline(fin, input_str);
		int i = 0;
		while (input_str[0] != '`')
		{
			keyword.push_back(input_str[0]);
			input_str.erase(input_str.begin());
		}
		input_str.erase(input_str.begin());
		this->add2Tree(keyword, input_str);

		// std::cout << keyword << " *** " << definition << "\n";
		keyword.clear();
	}
	fin.close();
}

void TernarySearchTree::import_emotional()
{
	std::ifstream fin("Library\\emotional.txt");
	std::string keyword; // processing keyword and def
	std::string input_str;
	while (!fin.eof())
	{
		std::getline(fin, input_str);
		int i = 0;
		while (input_str[0] != '\t')
		{
			keyword.push_back(input_str[0]);
			input_str.erase(input_str.begin());
		}
		input_str.erase(input_str.begin());
		this->add2Tree(keyword, input_str);
		// std::cout << keyword << " *** " << definition<<'\n';
		keyword.clear();
	}
	fin.close();
}

void TernarySearchTree::import_dictionary()
{
	std::ifstream fin("Library\\dictionary.txt");
	std::string keyword;
	std::string input_str;
	while (!fin.eof())
	{
		std::getline(fin, input_str);
		if (input_str.length() <= 3)
			continue;
		while (1)
		{
			keyword.push_back(input_str[0]);
			input_str.erase(input_str.begin());
			if (input_str[0] == ' ' && input_str[1] == ' ')
			{
				input_str.erase(input_str.begin());
				input_str.erase(input_str.begin());
				break;
			}
		}
		this->add2Tree(keyword, input_str);
		//std::cout << keyword << " *** " << definition<<'\n';
		keyword.clear();
	}
	fin.close();
}

TernarySearchTree* arr_of_Tree()
{
	TernarySearchTree arr_of_Tree[3];
	arr_of_Tree[0].import_slang();
	arr_of_Tree[1].import_emotional();
	arr_of_Tree[2].import_dictionary();
	return arr_of_Tree;
}