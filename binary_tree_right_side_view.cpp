/*************************************************************************
       File: binary_tree_right_side_view.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-08-16 09:54:12

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

************************************************************************/
#include "tools.h"

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> r;
        
        if (NULL == root) return r;
        
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        
        int start = 0, stop = 1;
        
        while (start < nodes.size()) {
            r.push_back(nodes.back()->val);
            
            while (start < stop) {
                TreeNode *node = nodes[start];
                
                if (node->left) nodes.push_back(node->left);
                if (node->right) nodes.push_back(node->right);
                
                start++;
            }
            
            stop = nodes.size();
        }
        
        return r;
    }
};


int main() {
    TreeNode n9(9, NULL, NULL);
    TreeNode n20(20, NULL, NULL);
    TreeNode n15(15, &n9, &n20);
    TreeNode n3(3, NULL, NULL);
    TreeNode root(7, &n3, &n15);
    
    vector<int> r = Solution().rightSideView(&root);
    print(r);
}
