#include "main.h"
#include "functions.h"

void main()
{
    TernarySearchTree arr_of_tree;
    arr_of_tree.import_dictionary();
    while (1) {
        std::string s;
        std::getline(std::cin, s);
        if (s == "") {
            break;
        }
        arr_of_tree.search4keyword(s);
    }
    arr_of_tree.deleteTree();

}


