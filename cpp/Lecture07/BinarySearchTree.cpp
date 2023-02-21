/**
 * Unbalanced Binary Search Tree (BST).
 * 
 * Author: Guoxi Liu
 * Clemson University
 * Date: 02/09/2023
 * 
*/
#include <iostream>
#include <queue>

/**
 * TreeNode class used for binary search tree. 
*/
struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode *right;
    TreeNode() = default;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
    TreeNode *root = nullptr;       // root node of the tree

public: 
    // Get the root node of the tree;
    const TreeNode * getRoot() const {
        return root;
    }

    // Insert a new value into the tree and return the root node. 
    void insert(int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
        }
        else {
            TreeNode *iter = root;
            while (iter != nullptr) {
                if (val <= iter->val) {
                    if (iter->left == nullptr) {
                        iter->left = new TreeNode(val);
                        break;
                    }
                    else {
                        iter = iter->left;
                    }
                }
                else {
                    if (iter->right == nullptr) {
                        iter->right = new TreeNode(val);
                        break;
                    }
                    else {
                        iter = iter->right;
                    }
                }
            }
        }
    }

    // Recursive function to remove a node in the tree.
    void remove(int val) {
        if (root == nullptr) return;

        TreeNode *iter = root;
        TreeNode *parent = nullptr;

        while (iter != nullptr) {
            // going to the left subtree
            if (val < iter->val) {
                parent = iter;
                iter = iter->left;
            }
            // going to the right subtree
            else if (val > iter->val) {
                parent = iter; 
                iter = iter->right;
            }
            // this is the node to be removed
            else {
                // the node is a leaf node
                if (iter->left == nullptr && iter->right == nullptr) {
                    if (parent) {
                        if (parent->left == iter) parent->left = nullptr;
                        else if (parent->right == iter) parent->right = nullptr;
                    }
                    delete iter;
                }
                // the node only has left child 
                else if (iter->right == nullptr) {
                    if (parent->left == iter) parent->left = iter->left;
                    if (parent->right == iter) parent->right = iter->left;
                    delete iter;
                }
                // the node only has right child
                else if (iter->left == nullptr) {
                    if (parent->left == iter) parent->left = iter->right;
                    if (parent->right == iter) parent->right = iter->right;
                    delete iter;
                }
                // the node is an internal node
                else {
                    // find the successor of the node
                    // which is the smallest node in the right subtree
                    TreeNode *successor = iter->right;
                    parent = nullptr;
                    while(successor && successor->left) {
                        parent = successor;
                        successor = successor->left;
                    }
                    // swap the value of successor with the node to be removed
                    iter->val = successor->val;
                    // then remove the successor node
                    // if the right subtree only has one child 
                    if (parent == nullptr) {
                        iter->right = nullptr;
                    }
                    else {
                        parent->left = successor->right;
                    }
                    delete successor;

                    // Bonus: replace the the node with its predecessor (i.e, the greatest value in the left subtree)
                }
                return;
            }
        }
    }

    // Preorder traversal of the tree
    void preorder(const TreeNode *node) {
        if (node == nullptr) return;
        std::cout << node->val << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Inorder traversal of the tree
    void inorder(const TreeNode *node) {
        if (node == nullptr) return;
        inorder(node->left);
        std::cout << node->val << " ";
        inorder(node->right);
    }

    // Traverse the tree level by level with BFS
    void levelOrder() const {
        if (root == nullptr) return;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode *n = q.front(); 
                q.pop();
                std::cout << n->val << " ";
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    BinarySearchTree testTree;
    // In-class exercise
    testTree.insert(30);
    testTree.insert(40);
    testTree.insert(50);
    testTree.insert(36);
    testTree.insert(24);
    testTree.insert(8);
    testTree.insert(58);
    testTree.insert(48);
    testTree.insert(26);
    testTree.insert(11);
    testTree.insert(13);
    testTree.levelOrder();
    std::cout << std::endl;

    testTree.remove(26);
    testTree.levelOrder();
    std::cout << std::endl;
    testTree.remove(8);
    testTree.levelOrder();
    std::cout << std::endl;
    testTree.remove(40);
    testTree.levelOrder();
    std::cout << std::endl;
    
    return 0;
}