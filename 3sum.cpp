/*************************************************************************
       File: 3sum.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2014-08-13 23:15:05

3Sum
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},
A solution set is:
	(-1, 0, 1)
	(-1, -1, 2)
************************************************************************/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int> &num)
	{
		vector<vector<int>> result;
		if(num.size() < 3)
			return result;

		sort(num.begin(), num.end());

		for(int i = 0; i < num.size()-2; i++)
		{
			if(i > 0 && num[i] == num[i-1])
				continue;
			int j = i+1, k = num.size()-1;
			while(j < k)
			{
				if(num[i] + num[j] + num[k] < 0)
					j++;
				else if(num[i] + num[j] + num[k] > 0)
					k--;
				else {
					vector<int> r;
					r.push_back(num[i]);
					r.push_back(num[j]);
					r.push_back(num[k]);
					result.push_back(r);

					while(num[j] == num[j+1] && j < k) j++;
					j++;
				}
			}
		}

		return result;
	}
};

int main()
{
	int A[] = {-1, 0, 1, 2, -1, -4};
	vector<int> num(&A[0], &A[0]+sizeof(A)/sizeof(0));

	vector<vector<int>> result = (new Solution())->threeSum(num);

	for_each(result.begin(), result.end(), [](vector<int> &vec) {
		cout<<"[";
		for_each(vec.begin(), vec.end(), [](int &i) {
			cout<<i<<", ";
		});
		cout<<"]"<<endl;
	});
}
