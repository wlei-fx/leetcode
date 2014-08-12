/*
Longest Consecutive Sequence
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution
{
public:
	int longestConsecutive(vector<int> &num)
	{
		// put elements into hash set
		unordered_set<int> set(num.begin(), num.end());
		int max = 0;
		
		for(auto iter = num.begin(); iter != num.end(); iter++)
		{
			int cur = *iter;
			// if find, then search consecutive element forward and backward
			// consecutive element can be removed for them have been counted
			auto itr = set.find(cur);
			if(set.end() != itr)
			{
				set.erase(itr);
				int curMax = 1, tmp = cur;
				while(set.end() != (itr = set.find(--tmp))) 
				{
					curMax++;
					set.erase(itr);
				}
				tmp = cur;
				while(set.end() != (itr = set.find(++tmp)))
				{
					curMax++;
					set.erase(itr);
				}
				max = max < curMax ? curMax : max;
			}
		}
		return max;
	}
};

int main()
{
	int A[] = {100, 4, 200, 1, 3, 2, 199, 201, 202, 204, 205, 203};
	vector<int> num(&A[0], &A[0]+sizeof(A)/sizeof(0));
	cout<<(new Solution())->longestConsecutive(num);
}
