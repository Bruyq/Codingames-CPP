#include "tree.h"

Tree::Tree(std::vector<int> vec)
{
    std::vector<int>::iterator it;
    it = vec.begin();
    root = new Node(*it);
    for (it = vec.begin() + 1; it != vec.end(); it++)
    {
        addNode(*it);
    }
}

Tree::~Tree()
{
    destroyFromNode(root);
}

void Tree::destroyFromNode(Node* leaf)
{
    // Destroying the nodes by traversing in Post-Order
    if (leaf->getLeft() != nullptr)
    {
        destroyFromNode(leaf->getLeft());
    }
    if (leaf->getRight() != nullptr)
    {
        destroyFromNode(leaf->getRight());
    }
    delete leaf;
}


void Tree::printPreOrder(Node* leaf)
{
    // Output current
    leaf->print();

    // Consider left
    if (leaf->getLeft() != nullptr)
    {
        Node* ptr = leaf->getLeft();
        printPreOrder(ptr);
    }

    // Consider right
    if (leaf->getRight() != nullptr)
    {
        Node* ptr = leaf->getRight();
        printPreOrder(ptr);
    }
}

void Tree::printInOrder(Node* leaf)
{
    // Consider left
    if (leaf->getLeft() != nullptr)
    {
        Node* ptr = leaf->getLeft();
        printInOrder(ptr);
    }

    // Output current
    leaf->print();

    // Consider right
    if (leaf->getRight() != nullptr)
    {
        Node* ptr = leaf->getRight();
        printInOrder(ptr);
    }
}

void Tree::printPostOrder(Node* leaf)
{
    // Consider Left
    if (leaf->getLeft() != nullptr)
    {
        Node* ptr = leaf->getLeft();
        printPostOrder(ptr);
    }

    // Consider right
    if (leaf->getRight() != nullptr)
    {
        Node* ptr = leaf->getRight();
        printPostOrder(ptr);
    }

    // Output current
    leaf->print();
}


void Tree::printLevelOrder(Node* leaf)
{
    std::vector<Node*> vec;
    vec.push_back(leaf);
    for (int i = 0; i != vec.size(); i++)
    {
        // Build stack while running through the vector
        if (vec[i]->getLeft() != nullptr)
        {
            vec.push_back(vec[i]->getLeft());
        }
        if (vec[i]->getRight() != nullptr)
        {
            vec.push_back(vec[i]->getRight());
        }
        
        // Output current
        vec[i]->print();
    }
}
