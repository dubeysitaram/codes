/*
Given an integer array nums and an integer k, 
return the k most frequent elements. 
You may return the answer in any order.

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size
*/


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {

            mp[nums[i]]++;
        }
        set<pair<int, int>> s;
        for (auto it : mp) {
            if (s.size() < k) {
                s.insert({it.second, it.first});
            } else {
                auto itr = *s.begin();
                if (itr.first < it.second) {
                    
                    s.erase(s.begin());
                    s.insert({it.second, it.first});
                }
            }
        }
        vector<int> ans;
        for (auto it : s) {
            ans.push_back(it.second);
        }
        return ans;
    }
};