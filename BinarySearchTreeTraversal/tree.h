#pragma once

#include "node.h"

class Tree
{
private:
    Node* root = nullptr;

public:
    Tree() {};
    Tree(int val) {root = new Node(val);}
    Tree(std::vector<int> vec);
    ~Tree();
    void destroyFromNode(Node* leaf);
    void addNode(int val) { Node* n = new Node(val); root->setChild(n); }
    Node* getRoot() { return root; }
    void printPreOrder(Node* leaf);
    void printInOrder(Node* leaf);
    void printPostOrder(Node* leaf);
    void printLevelOrder(Node* leaf);
};
