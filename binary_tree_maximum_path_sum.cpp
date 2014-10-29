/************************************
Binary Tree Maximum Path Sum

Given a binary tree, find the maximum path sum.
The path may start and end at any node in the tree.

For example:
Given the below binary tree,
       1
	  / \
	 2   3
Return 6.
************************************/

#include "tools.h"

class Solution
{
public:
	int maxPathSum(TreeNode *root)
	{
		int child_max = INT_MIN, cur_max;
		cur_max = maxPathSum(root, child_max);

		return cur_max > child_max ? cur_max : child_max;
	}

	int maxPathSum(TreeNode *root, int &child_max)
	{
		if(NULL == root)
			return 0;


		int left_max = maxPathSum(root->left, child_max);
		int right_max = maxPathSum(root->right, child_max);

		int cur_max = root->val;
		if(left_max >= 0)
			cur_max += left_max;
		if(right_max >= 0)
			cur_max += right_max;
		
		child_max = child_max > cur_max ? child_max : cur_max;
		int half_max = left_max > right_max ? left_max : right_max;
		return (half_max > 0 ? half_max : 0) + root->val;
	}
};

int main()
{
	int A[] = {9,6,-3,INT_MIN,INT_MIN,-6,2,INT_MIN,INT_MIN,2,INT_MIN,-6,-6,-6};
	vector<int> vals(A, A+sizeof(A)/sizeof(int));
	
	TreeNode *root = makeTree(vals);
	preorder(root);cout<<endl;
	inorder(root);cout<<endl;
	cout<<((new Solution())->maxPathSum(root))<<endl;
}
