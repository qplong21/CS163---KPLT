#include "main.h"
#include "functions.h"

void main()
{
    TernarySearchTree a;
    a.import_slang();
    std::string input_str;
    while (1)
    {
        std::cout << "Searching: ";
        std::getline(std::cin, input_str);
        a.search4keyword(input_str);
    }
    a.deleteTree();
}
