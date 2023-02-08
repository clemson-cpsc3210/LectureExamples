/**
 * Tree-based implementation for the union find algorithm.
 * 
 * Author: Guoxi Liu
 * Clemson University
 * Date: 02/05/2023
*/
#include <cassert>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

class UnionFind
{

    // Define the helper class Node
    struct Node {
        int val;
        Node *parent_ptr;
        int rank;
    };

private:
    std::list<Node*> all_nodes;     // keep track of nodes 
    std::unordered_map<int, Node*> mp;    // map the integer value to the Node

public:
    UnionFind() {}
    // Destructor needs to remove all the header pointers
    ~UnionFind() {
        for(auto &n : all_nodes) delete n;
    }
    
    void MakeSet(int v) {
        Node *node = new Node();
        node->val = v;
        node->parent_ptr = node;
        node->rank = 1;
        all_nodes.push_back(node);
        mp[v] = node;
    }

    Node* Find(int x) {
        Node *node_x = mp.at(x);
        Node *root = node_x;
        while (root->parent_ptr != root) {
            root = root->parent_ptr;
        }
        // Path compression 
        Node *iter = node_x;
        while (iter->parent_ptr != iter) {
            Node *tmp = iter;
            iter = iter->parent_ptr;
            tmp->parent_ptr = root;
        }
        return root;
    }

    void Union(int x, int y) {
        Node *set_x = Find(x);
        Node *set_y = Find(y);
        // Union by size 
        if (set_x->rank < set_y->rank) {
            set_x->parent_ptr = set_y;
            set_y->rank += set_x->rank;
        } 
        else {
            set_y->parent_ptr = set_x;
            set_x->rank += set_y->rank;
        }
    }

    // Print the rank and parent of each node 
    void Print() {
        for (auto &kv : mp) {
            std::cout << kv.first << ": rank " << kv.second->rank << ", parent " << kv.second->parent_ptr->val << std::endl;
        }
    }
};


/**
 * Main entry. 
*/
int main()
{
    UnionFind uf;
    // In-class exercise example. 
    for (int i = 1; i <= 16; i++) uf.MakeSet(i);
    for (int i = 1; i < 16; i+=2) uf.Union(i, i+1);
    for (int i = 1; i < 14; i+=4) uf.Union(i, i+2);

    uf.Union(1, 5);
    uf.Union(11, 13);
    uf.Union(1, 10);

    std::cout << "Find(2): " << uf.Find(2) << std::endl;
    std::cout << "Find(9): " << uf.Find(9) << std::endl;
    
    return 0;
}
