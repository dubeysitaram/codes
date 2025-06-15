/*
You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.


Constraints:

1 <= nums1.length, nums2.length <= 105
-109 <= nums1[i], nums2[i] <= 109
nums1 and nums2 both are sorted in non-decreasing order.
1 <= k <= 104
k <= nums1.length * nums2.length
*/

// heap apne aap decide kar legi kis index pe aage badna chaiye // ye mat soch
// heap apne dono option ko apne daal legi aur vo appne aap lowest sum ke according sort ho jayegna
// jo ek baar process ho gaya vo phir proccess nhi hona chaiye

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
	set<pair<int, pair<int, int>>> pq;
	set<pair<int, int>> visited;
	int n1 = nums1.size(), n2 = nums2.size();
	int i = 0, j = 0;
	visited.insert({0, 0});
	pq.insert({nums1[i] + nums2[j], {i, j}});
	vector<vector<int>> ans;
	while (!pq.empty() && k > 0) {
		pair<int, pair<int, int>> p = *pq.begin();
		pq.erase(pq.begin());
		i = p.second.first;
		j = p.second.second;
		ans.push_back({nums1[i], nums2[j]});
		if (i + 1 < n1 && visited.find({i + 1, j}) == visited.end()) {
			visited.insert({i + 1, j});
			pq.insert({nums1[i + 1] + nums2[j], {i + 1, j}});
		}
		if (j + 1 < n2 && visited.find({i, j + 1}) == visited.end()) {
			visited.insert({i, j + 1});
			pq.insert({nums1[i] + nums2[j + 1], {i, j + 1}});
		}
		k--;
	}
	return ans;
}