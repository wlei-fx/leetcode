/*************************************************************************
       File: binary_search_tree_iterator.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-08-14 18:31:11

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

 

Example:
            7
           / \
          3  15
            /  \
           9   20

BSTIterator iterator = new BSTIterator(root);
iterator.next();    // return 3
iterator.next();    // return 7
iterator.hasNext(); // return true
iterator.next();    // return 9
iterator.hasNext(); // return true
iterator.next();    // return 15
iterator.hasNext(); // return true
iterator.next();    // return 20
iterator.hasNext(); // return false

************************************************************************/
#include "tools.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTIterator {
private:
    stack<TreeNode *> s;
public:
    BSTIterator(TreeNode* root) {
        prepare(root);
    }
    
    void prepare(TreeNode* node) {
        while(node) {
            s.push(node);
            node = node->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *node = s.top();
        s.pop();
        
        prepare(node->right);
        
        return node->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};

int main() {
    TreeNode n9(9, NULL, NULL);
    TreeNode n20(20, NULL, NULL);
    TreeNode n15(15, &n9, &n20);
    TreeNode n3(3, NULL, NULL);
    TreeNode root(7, &n3, &n15);
    
    BSTIterator iterator(&root);
    cout<<iterator.next()<<endl;    // return 3
    cout<<iterator.next()<<endl;    // return 7
    cout<<iterator.hasNext()<<endl; // return true
    cout<<iterator.next()<<endl;    // return 9
    cout<<iterator.hasNext()<<endl; // return true
    cout<<iterator.next()<<endl;    // return 15
    cout<<iterator.hasNext()<<endl; // return true
    cout<<iterator.next()<<endl;    // return 20
    cout<<iterator.hasNext()<<endl; // return false
    
}
