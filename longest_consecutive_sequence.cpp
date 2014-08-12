/*
Longest Consecutive Sequence
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	int longestConsecutive(vector<int> &num)
	{
		return num.size();
	}
};

int main()
{
	int A[] = {100, 4, 200, 1, 3, 2};
	vector<int> num(&A[0], &A[0]+sizeof(A)/sizeof(0));
	cout<<(new Solution())->longestConsecutive(num);
}
