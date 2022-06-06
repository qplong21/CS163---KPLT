#include "main.h"
#include "functions.h"

void main()
{
    TernarySearchTree a;
    a.import_slang();
    std::string input_str;
    for(int i=0;i<5;++i)
    {
        std::cout << "Searching: ";
        std::getline(std::cin, input_str);
        a.search4keyword(input_str);
    }
    a.deleteTree();
}


