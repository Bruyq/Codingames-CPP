#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class Node
{
private:
    int value;
    Node* l_child = nullptr, * r_child = nullptr;

public:
    Node() {};
    ~Node() {};
    Node(int val) { value = val; }
    int getValue() { return value; }
    Node* getLeft() { return l_child; }
    Node* getRight() { return r_child; }
    void setChild(Node* c);
    void print() { std::cout << value << " "; }
};

