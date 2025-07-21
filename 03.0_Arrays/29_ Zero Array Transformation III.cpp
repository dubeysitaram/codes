// 3362. Zero Array Transformation III

/*
You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].

Each queries[i] represents the following action on nums:

Decrement the value at each index in the range [li, ri] in nums by at most 1.
The amount by which the value is decremented can be chosen independently for each index.
A Zero Array is an array with all its elements equal to 0.

Return the maximum number of elements that can be removed from queries,
such that nums can still be converted to a zero array using the remaining queries.
If it is not possible to convert nums to a zero array, return -1.

Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
1 <= queries.length <= 10^5
queries[i].length == 2
0 <= li <= ri < nums.length
*/

class Solution {
public:
	int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
		int n = nums.size();
		int m = queries.size();
		sort(queries.begin(), queries.end());
		int i = 0;
		priority_queue<int> pq;
		int j = 0;
		int used = 0;
		multiset<int> ms;
		while (i < n) {
			while (j < m && queries[j][0] <= i) {
				pq.push(queries[j][1]);
				j++;
			}
			if (nums[i] <= ms.size()) {
				nums[i] = 0;
				i++;
			} else {
				nums[i] = nums[i] - ms.size();
				while (nums[i] != 0 && !pq.empty()) {
					if (pq.top() >= i)nums[i]--;
					if (pq.top() > i)ms.insert(pq.top());
					pq.pop();
				}
				if (nums[i] != 0)return -1;
				i++;
			}
			while (!ms.empty() && *ms.begin() < i) {
				ms.erase(ms.begin());
			}
		}
		return pq.size();
	}
};
