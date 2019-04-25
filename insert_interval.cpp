/*************************************************************************
       File: insert_interval.cpp.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2019-04-25 19:17:56

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

************************************************************************/
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> r;
        
        int i = 0;
        bool merged = false;
        vector<int> c;
        for (int i = 0; i < intervals.size(); i++) {
            c = intervals[i];
            
            if (merged) {
                r.push_back(c);
                continue;
            }
            
            if(c[0] > newInterval[1]) {
                r.push_back(newInterval);
                merged = true;
                r.push_back(c);
            } else if (c[1] < newInterval[0]) {
                r.push_back(c);
            } else {
                newInterval[0] = min(c[0], newInterval[0]);
                newInterval[1] = max(c[1], newInterval[1]);
            }
        }
        
        if (!merged) {
            r.push_back(newInterval);
        }
        
        return r;
    }
};

int main() {
    int a[][2] = {{1,3}, {6,9}};
    int b[] = {2,5};
    
    vector<vector<int>> intervals;
    vector<int> newInterval(begin(b), end(b));
    for (int i = 0; i < 2; i++) {
        vector<int> n(begin(a[i]), end(a[i]));
        intervals.push_back(n);
        
        cout<<n[0]<<n[1]<<endl;
    }
    
    vector<vector<int>> r = Solution().insert(intervals, newInterval);
    for (int i = 0; i < r.size(); i++) {
        cout<<r[i][0]<<" "<<r[i][1]<<endl;
    }
}
