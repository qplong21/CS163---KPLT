#include "main.h"
#include "functions.h"

bool isLetter(char ch, bool capital = false) {
	if (!capital)
		return (ch >= 'a' && ch <= 'z');
	return (ch >= 'A' && ch <= 'Z');
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
TernaryTreeNode* TernarySearchTree::getRandomWord(bool normal, int i) {
	std::string word = "";

	int c;
	bool done = false;
	char ch = 65 + rand() % 26;
	std::string startChar(1, ch);
	TernaryTreeNode* tem = nullptr;
	bool start = true;
	bool turned = false;
	bool outFirstTwoChar = true;
	while (1) {
		if (start) {
			do {
				ch = 97 + rand() % 26;
				std::string addChar(1, ch); //de check lai cai random nay no ra tu gi
				word = startChar + addChar;
				tem = search4keyword(word, false);
			} while (!tem);
			start = false;
			turned = false;
		}
		else {
			c = rand() % 5;
			if (c == 0) {
				if (tem->right && isLetter(tem->right->ch)) {
					//phai them delete char trc o day
					if (!turned)
						word.pop_back();
					tem = tem->right;
					word += tem->ch;
					turned = true;
				}
				else if (!tem->right)
					if (tem->definition)
						break;
			}
			else if (c == 1) {
				if (tem->left && isLetter(tem->left->ch))
				{
					if (!turned)
						word.pop_back();
					tem = tem->left;
					word += tem->ch;
					turned = true;
				}
				else if (!tem->left)
					if (tem->definition)
						break;
			}
			else {
				if (tem->mid) {
					std::string addChar(1, tem->mid->ch);

					word += addChar;
					tem = tem->mid;
					turned = false;
				}
				else if (!tem->mid)
					if (tem->definition)
						break;
			}
			//de ti kiem cach random khac
		}
	}
	if (normal) {
		std::cout << word << " - " << *tem->definition << "\n";
	}
	else {
		std::pair<std::string, std::string> newPair;
		newPair.first = word;
		newPair.second = *tem->definition;
		this->wordAndDefinition[i] = newPair;
	}
	return tem;

}
void TernarySearchTree::guessRandomWord() {
	for (int i = 0; i < 4; i++) {
		getRandomWord(false, i);
	}
	int chooseWord = rand() % 4;
	std::cout << "The word has this definition: \n" << wordAndDefinition[chooseWord].second << "\nPlease choose the correct word: \n";
	for (int i = 0; i < 4; i++) {
		std::cout << i + 1 << ". " << wordAndDefinition[i].first << "\n";
	}
	std::cout << "Please choose your answer: ";
	int in;
	std::cin >> in;
	if ((in - 1) == chooseWord) {
		std::cout << "Congratulations, you got the correct answer!";
	}
	else {
		std::cout << "WASTED, the correct answer is " << wordAndDefinition[chooseWord].first;
	}
}
void TernarySearchTree::guessRandomDefinition() {
	for (int i = 0; i < 4; i++) {
		getRandomWord(false, i);
	}
	int chooseWord = rand() % 4;
	std::cout << "The word is: \n" << wordAndDefinition[chooseWord].first << "\nPlease choose the correct definition: \n";
	for (int i = 0; i < 4; i++) {
		std::cout << i + 1 << ". " << wordAndDefinition[i].second << "\n";
	}
	std::cout << "Please choose your answer: ";
	int in;
	std::cin >> in;
	if ((in - 1) == chooseWord) {
		std::cout << "Congratulations, you got the correct answer!";
	}
	else {
		std::cout << "WASTED, the correct answer is " << wordAndDefinition[chooseWord].second;
	}
}
void TernarySearchTree::addNewWordToDict() {
	std::string keyword, definition;
	std::cout << "Please enter the word you want to add: ";
	std::getline(std::cin, keyword);
	std::cin.ignore(1000, '\n');
	std::cout << "Please enter the definition of the word: ";
	std::getline(std::cin, definition);
	add2Tree(keyword, definition, 0);
}
void TernarySearchTree::add2Tree(std::string keyword, std::string definition, bool importing)
{
	if (!this->root)
	{
		this->root = new TernaryTreeNode;
		this->root->ch = 'n';
		this->root->definition = new std::string;
		*this->root->definition = "The letter N";
	}
	TernaryTreeNode* tem = this->root;
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
					//da co trong tu dien
					if (!importing) {
						std::cout << "The word " << keyword << " is already in the dictionary \nDo you want to edit its definition instead?";
						char in;
						std::cin >> in;
						if (toupper(in) == 'Y') {
							std::string newDefinition;
							std::getline(std::cin, newDefinition);
							std::cin.ignore(10000, '\n');
							editKeyword(tem, newDefinition);
							std::cout << "Update new definition successfully for " << keyword << "\n";
						}
						return;
					}
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
	if (!importing)
		std::cout << "Added successfully word " << keyword << "\n";
}
void TernarySearchTree::editKeyword(TernaryTreeNode*& tem, std::string newDefinition) {
	*tem->definition = newDefinition;
	//de them cai save ra file nua
}
TernaryTreeNode* TernarySearchTree::search4keyword(std::string keyword, bool normal)
{
	// those line with "//" at the end is for debug
	// chinh cho viet hoa thuong search van duoc
	TernaryTreeNode* tem = this->root;
	// int count = 0;//
	for (int i = 0; i < keyword.length(); ++i)
	{
		if (tem == nullptr)
		{
			if (normal)
				std::cout << "Not found\n";
			// std::cout << "Pass over " << count << " nodes\n";//
			return tem;
		}
		//++count;//
		// std::cout << tem->ch;//
		if (tem->ch == keyword[i])
		{
			if (i == keyword.length() - 1) //den dung tu
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
			--i; //de no kh tang len qua chu ke tiep
			continue;
		}
		if (tem->ch < keyword[i]) // go right
		{
			tem = tem->right;
			--i;
			continue;
		}
	}
	if (normal) {
		if (tem->definition)
		{
			std::cout << *tem->definition << "\n";
		}
		else
			std::cout << "Not found\n";
	}
	// std::cout << "Pass over " << count << " nodes\n";//
	return tem;
}


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
		this->add2Tree(keyword, input_str, 1);

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
		this->add2Tree(keyword, input_str, 1);
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
		this->add2Tree(keyword, input_str, 1);
		// std::cout << keyword << " *** " << definition<<'\n';
		keyword.clear();
	}
	fin.close();
}

void TernarySearchTree::deleteKeword(std::string keyword)
{
	TernaryTreeNode* tem = this->root, * breakpoint = nullptr;
	std::vector<TernaryTreeNode*> myVec;
	for (int i = 0; i < keyword.length(); ++i)
	{
		if (tem == nullptr)
		{
			return;
		}
		if (tem->ch == keyword[i])
		{
			if (i == keyword.length() - 1) //den dung tu
			{
				break;
			}
			else
			{
				if (childOfNode(tem) == 1 && tem->definition == nullptr)
					myVec.push_back(tem);
				else
				{
					breakpoint = tem;
					myVec.clear();
				}
				tem = tem->mid;
				continue;
			}
		}
		if (tem->ch > keyword[i]) // go left
		{
			if (childOfNode(tem) == 1 && tem->definition == nullptr)
				myVec.push_back(tem);
			else
			{
				breakpoint = tem;
				myVec.clear();
			}
			tem = tem->left;
			--i;
			continue;
		}
		if (tem->ch < keyword[i]) // go right
		{
			if (childOfNode(tem) == 1 && tem->definition == nullptr)
				myVec.push_back(tem);
			else
			{
				breakpoint = tem;
				myVec.clear();
			}
			tem = tem->right;
			--i;
			continue;
		}
	}
	if (tem->definition)
	{
		if (childOfNode(tem))
		{
			delete tem->definition;
			tem->definition = nullptr;
			return;
		}
		if (myVec.empty() && breakpoint)
		{
			if (breakpoint->left == tem)
				breakpoint->left = nullptr;
			else if (breakpoint->mid == tem)
				breakpoint->mid = nullptr;
			else if (breakpoint->right == tem)
				breakpoint->right = nullptr;
			return;
		}
		delete tem->definition;
		delete tem;
		if (breakpoint->left == myVec[0])
			breakpoint->left = nullptr;
		else if (breakpoint->mid == myVec[0])
			breakpoint->mid = nullptr;
		else if (breakpoint->right == myVec[0])
			breakpoint->right = nullptr;
		else
			return;
		for (int i = 0; i < myVec.size(); ++i)
		{
			delete myVec[i];
		}
		myVec.clear();
	}
}

TernaryTreeNode* TernarySearchTree::getRoot()
{
	return this->root;
}