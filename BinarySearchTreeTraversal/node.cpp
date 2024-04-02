#include "node.h"

void Node::setChild(Node* c)
{
    if (c->getValue() < value)
    {
        if (l_child == nullptr)
        {
            l_child = c;
        }
        else
        {
            l_child->setChild(c);
        }
    }
    else
    {
        if (r_child == nullptr)
        {
            r_child = c;
        }
        else
        {
            r_child->setChild(c);
        }
    }
}