#ifndef __TOOLS_H__
#define __TOOLS_H__

#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define INT_MAX ((int)0x7fffffff)
#define INT_MIN ((int)0x80000000)

template <class T>
void print(vector<T> &v)
{
	cout<<"[";
	for_each(v.begin(), v.end(), [](T t) {
		cout<<t<<",";		
	});
	cout<<"]"<<endl;
}

template <class T>
void print(vector<vector<T>> &v)
{
	for_each(v.begin(), v.end(), [](vector<T> &vec) {
		print(vec);
	});
}

template <class T>
void print(T *arr, int size)
{
	cout<<"[";
	for_each(arr, arr+size, [](T t) {
		cout<<t<<",";
	});
	cout<<"]"<<endl;
}

template <class T>
void print(T **arr, int row, int col)
{
	for(int i = 0; i < row; i++)
	{
		cout<<"[";
		for(int j = 0; j < col; j++)
		{
			cout<<arr[i][j]<<",";
		}
		cout<<"]"<<endl;
	}
}

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v): val(v), left(NULL), right(NULL) {}
};

TreeNode *makeTree(vector<int> vals)
{
	vector<TreeNode *> nodes;
	for(int i = 0, parent = -1; i < vals.size(); parent += 1)
	{
		if(-1 == parent)
		{
			nodes.push_back(new TreeNode(vals[i]));
			i += 1;
		} else {
			if(INT_MIN != vals[i])
			{
				nodes[parent]->left = new TreeNode(vals[i]);
				nodes.push_back(nodes[parent]->left);
			}
			i += 1;

			if(i < vals.size())
			{
				if(INT_MIN != vals[i])
				{
					nodes[parent]->right = new TreeNode(vals[i]);
					nodes.push_back(nodes[parent]->right);
				}
				i += 1;
			}
		}
	}

	return nodes.front();
}

void preorder(TreeNode *root)
{
	if(NULL == root)
		return ;

	cout<<root->val<<",";
	preorder(root->left);
	preorder(root->right);
}

void inorder(TreeNode *root)
{
	if(NULL == root)
		return ;

	inorder(root->left);
	cout<<root->val<<",";
	inorder(root->right);
}
#endif
