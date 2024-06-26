#include "tree.h"


// Input example : 
// 5
// 8 6 13 10 5
//
// Output example : 
// 8 6 5 13 10  (Graph traversed in Pre-Order)
// 5 6 8 10 13  (Graph traversed in In-Order)
// 5 6 10 13 8  (Graph traversed in Post-Order)
// 8 6 13 5 10  (Graph traversed in Level-Order/Breadth-First-Search)
//
int main()
{
    std::cout << "Please enter the number of elements constituting the binary tree, and then the elements, one at a time :\n";
    std::vector<int> input;
    int n;
    std::cin >> n; std::cin.ignore();
    for (int i = 0; i < n; i++) {
        int vi;
        std::cin >> vi; std::cin.ignore();
        input.push_back(vi);
    }
    
    Tree btree(input);

    std::cout << "Pre-Order binary tree traversal :\t";
    btree.printPreOrder(btree.getRoot());
    std::cout << std::endl;

    std::cout << "In-Order binary tree traversal :\t";
    btree.printInOrder(btree.getRoot());
    std::cout << std::endl;

    std::cout << "Post-Order binary tree traversal :\t";
    btree.printPostOrder(btree.getRoot());
    std::cout << std::endl;

    std::cout << "Level-Order binary tree traversal :\t";
    btree.printLevelOrder(btree.getRoot());
    std::cout << std::endl;

    std::cout << "Done !";
}