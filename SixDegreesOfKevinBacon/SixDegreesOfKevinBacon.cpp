#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
#include <limits.h>

// Input format specific custom split
// Input format is like :
// Film name: Actor1, Actor2, Actor3, Actor4
std::vector<std::string> custom_split(std::string str)
{
    std::vector<std::string> splitted;
    str = str.substr(str.find(':') + 2);
    int i = str.find(", ");
    while (i != std::string::npos)
    {
        splitted.push_back(str.substr(0, i));
        str = str.substr(i + 2);
        i = str.find(", ");
    }
    splitted.push_back(str.substr(0, i));
    return splitted;
}


class Node
{
private:
    std::string m_name;                     // Value of the node
    std::vector<std::string> m_neighbors;   // Edges of the node
    int m_distance = INT_MAX;               // Distance from the node of interest : Infinity by default

public:
    Node() {};
    Node(std::string name, std::vector<std::string> casting)
    {
        m_name = name;
        for (std::vector<std::string>::iterator it = casting.begin(); it != casting.end(); it++)
        {
            // All strings other than the m_name are added to the neighbors vector
            if ((*it) != m_name)
            {
                m_neighbors.push_back(*it);
            }
        }
    }
    ~Node() {};
    void addNeighbors(std::vector<std::string> casting)
    {
        for (std::vector<std::string>::iterator it = casting.begin(); it != casting.end(); it++)
        {
            // Check that current string is not in the neighbors
            if (std::find(m_neighbors.begin(), m_neighbors.end(), (*it)) == m_neighbors.end())
            {
                m_neighbors.push_back(*it);
            }
        }
    }

    friend class Graph;
};


class Graph
{
private:
    std::map<std::string, Node*> m_table;   // Associative table between string and Node

public:
    Graph() {};
    ~Graph()
    {
        // Delete all nodes
        for (std::map<std::string, Node*>::iterator it = m_table.begin(); it != m_table.end(); it++)
        {
            delete it->second;
        }
    }
    void addNodes(std::string casting)
    {
        std::vector<std::string> vec_casting = custom_split(casting);
        for (std::vector<std::string>::iterator it = vec_casting.begin(); it != vec_casting.end(); it++)
        {
            // If the current string "*it" isn't yet a key of the table, create a node and associate a key to this node in the table, otherwise add new neighbors to the node corresponding to the key "*it"
            if (m_table.find(*it) == m_table.end())
            {
                Node* n = new Node(*it, vec_casting);
                m_table[*it] = n;
            }
            else
            {
                m_table[*it]->addNeighbors(vec_casting);
            }
        }
    }
    void breadthFirstSearch(std::string root_name)
    {
        // Standard Breadth-First-Search algorithm
        // Initialize all nodes distance to inf
        for (std::map<std::string, Node*>::iterator it = m_table.begin(); it != m_table.end(); it++)
        {
            it->second->m_distance = INT_MAX;
        }

        // Initialize root node distance,initialize stack
        m_table[root_name]->m_distance = 0;
        std::stack<Node*> pile;
        pile.push(m_table[root_name]);

        // The stack will be empty only when all nodes somewhat connected to root node have been traversed
        while (!pile.empty())
        {
            Node* node_ptr = pile.top();
            pile.pop();

            for (std::vector<std::string>::iterator it = node_ptr->m_neighbors.begin(); it != node_ptr->m_neighbors.end(); it++)
            {
                // If the distance is inf, the node hasn't been yet traversed, so update it's distance and put it in the stack
                if (m_table[*it]->m_distance == INT_MAX)
                {
                    m_table[*it]->m_distance = node_ptr->m_distance + 1;
                    pile.push(m_table[*it]);
                }
            }
        }
    }
    int getDistance(std::string root_name, std::string end_name)
    {
        breadthFirstSearch(root_name);
        return m_table[end_name]->m_distance;
    }
};

// Input exemple (output result should be 2): 
// Elvis Presley
// 3
// Change of Habit : Elvis Presley, Mary Tyler Moore, Barbara McNair, Jane Elliot, Ed Asner
// JFK : Kevin Costner, Kevin Bacon, Tommy Lee Jones, Laurie Metcalf, Gary Oldman, Ed Asner
// Sleepers : Kevin Bacon, Jason Patric, Brad Pitt, Robert De Niro, Dustin Hoffman
int main()
{
    std::string actor_name;
    std::getline(std::cin, actor_name);
    int n;
    std::cin >> n; std::cin.ignore();
    Graph actors;
    for (int i = 0; i < n; i++) {
        std::string movie_cast;
        std::getline(std::cin, movie_cast);
        actors.addNodes(movie_cast);
    }

    std::cout << actors.getDistance(actor_name, "Kevin Bacon") << std::endl;
}