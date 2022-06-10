#include "main.h"
#include "functions.h"

int main()
{
    TernarySearchTree arr_of_tree;
    arr_of_tree.import_dictionary();
<<<<<<< HEAD
    while (1)
    {
        std::string s;
        std::getline(std::cin, s);
        if (s == "")
        {
=======
    std::cout << "done";
    while (1) {
        std::string s;
        std::getline(std::cin, s);
        if (s == "")
>>>>>>> 74b91c22155454e4a437ba654cb08f394dc792b8
            break;
        arr_of_tree.search4keyword(s);
    }
    arr_of_tree.deleteTree();
}
