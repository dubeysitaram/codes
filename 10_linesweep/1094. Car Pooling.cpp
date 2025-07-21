/*1094. Car Pooling.cpp
There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi]
indicates that the ith trip has numPassengersi passengers and the locations to pick them up and
drop them off are fromi and toi respectively.
The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

*/
class Solution {
public:
	bool carPooling(vector<vector<int>>& trips, int capacity) {
		int n = trips.size();
		map<int, int>mp;
		for (int i = 0; i < n; i++) {
			int l = trips[i][1];
			int r = trips[i][2];
			int val = trips[i][0];
			mp[l] += val;
			mp[r] -= val;
		}
		int sum = 0;
		for (auto it : mp) {
			if (sum + it.second > capacity)return false;
			sum += it.second;
		}
		return true;
	}
};