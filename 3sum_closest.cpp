/*************************************************************************
       File: 3sum_closest.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2014-08-12 22:08:09

3Sum Closest
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
For example, given array S = {-1 2 1 -4}, and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int threeSumClosest(vector<int> &num, int target)
	{
		int closest = 0;
		if(num.size() < 3)
			return closest;

		sort(num.begin(), num.end());
		closest = num[0] + num[1] + num[2];

		for(int i = 0; i < num.size()-2; i++)
		{
			if(i > 0 && num[i] == num[i-1])
				continue;
			int j = i+1, k = num.size()-1;
			while(j < k)
			{
				int sum = num[i] + num[j] + num[k];
				if(abs(target-closest) > abs(target-sum))
					closest = sum;
				if(sum < target)
					j++;
				else if(sum > target)
					k--;
				else
					return target;
			}
		}

		return closest;
	}
};

int main()
{
	int A[] = {-1, 2, 1, -4};
	vector<int> num(&A[0], &A[0]+sizeof(A)/sizeof(0));

	cout<<(new Solution())->threeSumClosest(num, 1);
}
