#include "main.h"
#include "functions.h"

void main()
{
    TernarySearchTree a;
    a.import_dictionary();
    std::cout << "done\n";
    std::string str;
    while (true)
    {
        std::getline(std::cin, str);
        if (str.empty())
            break;
        a.search4keyword(str);
        
    }
    a.deleteTree();
}


