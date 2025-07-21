/*

1851_Min_Interval_toInclude_Each_Query.cpp


You are given a 2D integer array intervals, where intervals[i] = [lefti, righti]
 describes the ith interval starting at lefti and ending at righti (inclusive).
 The size of an interval is defined as the number of integers it contains, or more formally righti - lefti + 1.

You are also given an integer array queries.
The answer to the jth query is the size of the smallest interval i such that lefti <= queries[j] <= righti.
If no such interval exists, the answer is -1.

Return an array containing the answers to the queries.
*/

class Solution {
public:
	vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
		int n = intervals.size();
		vector<vector<int>> events; // will store the {left/right,type,length}
		for (int i = 0; i < n; i++) {
			events.push_back(
			{intervals[i][0], 0, intervals[i][1] - intervals[i][0] + 1});
			events.push_back(
			{intervals[i][1], 2, intervals[i][1] - intervals[i][0] + 1});
		}
		for (int i = 0; i < queries.size(); i++) {
			events.push_back({queries[i], 1, i});
		}
		sort(events.begin(), events.end());
		vector<int> ans(queries.size(), -1);
		multiset<int> ms;
		for (int i = 0; i < events.size(); i++) {
			if (events[i][1] == 0) {
				ms.insert(events[i][2]);
			} else if (events[i][1] == 1 ) {
				if (ms.size() > 0) ans[events[i][2]] = *ms.begin();
			} else  {
				ms.erase(ms.find(events[i][2]));
			}
		}
		return ans;
	}
};
// class Solution {
// public:
//     vector<int> minInterval(vector<vector<int>>& intervals,
//                             vector<int>& queries) {
//         int n = intervals.size();
//         vector<vector<int>> events; // will store the {left/right,type,length}
//         for (int i = 0; i < n; i++) {
//             events.push_back(
//                 {intervals[i][0], -1, intervals[i][1] - intervals[i][0] + 1});
//             events.push_back(
//                 {intervals[i][1], 1, intervals[i][1] - intervals[i][0] + 1});
//         }
//         for (int i = 0; i < queries.size(); i++) {
//             events.push_back({queries[i], 0, i});
//         }
//         sort(events.begin(), events.end());
//         vector<int> ans(queries.size(), -1);
//         multiset<int> ms;
//         for (int i = 0; i < events.size(); i++) {
//             if (events[i][1] == -1) {
//                 ms.insert(events[i][2]);
//             } else if (events[i][1] == 0 && !ms.empty()) {
//                 ans[events[i][2]] = *ms.begin();
//             } else if (events[i][1] == 1) {
//                 ms.erase(ms.find(events[i][2]));
//             }
//         }
//         return ans;
//     }
// };
