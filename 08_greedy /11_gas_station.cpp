/*

134. Gas Station

There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station
to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel
around the circuit once in the clockwise direction, otherwise return -1.
If there exists a solution, it is guaranteed to be unique.



*/

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = cost.size();
		int sum_gas = accumulate(gas.begin(), gas.end(), 0);
		int sum_cost = accumulate(cost.begin(), cost.end(), 0);
		if (sum_gas < sum_cost)
			return -1;
		int have = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			have += gas[i];
			if (have - cost[i] >= 0) { // agge bhado isi answer index ko lekar
				have = have - cost[i];
			} else {    // pichala answer possible nhi ho skta hence update it
				ans = i + 1;
				have = 0;
			}
		}
		return ans;
	}
};