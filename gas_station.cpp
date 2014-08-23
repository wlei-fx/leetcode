/*************************************************************************
       File: gas_station.cpp
         By: navy
      Email: leiwei1990@gmail.com
Create Time: 2014-08-23 23:59:19

Gas Station 
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
************************************************************************/

#include "tools.h"
class Solution
{
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
	{
		int n = gas.size();
		vector<int> spare;
		for(int i = 0; i < n; i++)
			spare.push_back(gas[i]-cost[i]);

		for(int i = 0; i < n; i++)
		{
			int total = 0;
			for(int j = i; j < i+n; j++)
			{
				total += spare[j%n];
				if(total < 0)				// 如果total<0，说明从i出发不能到达j
					break;
			}
			if(total >= 0)
				return i;
		}

		return -1;
	}
};

int main()
{
	int GAS[] = {10, 5};
	int COST[] = {6, 9};
	vector<int> gas(GAS, GAS+sizeof(GAS)/sizeof(0));
	vector<int> cost(COST, COST+sizeof(COST)/sizeof(0));

	cout<<(new Solution())->canCompleteCircuit(gas, cost);
	return 0;
}

