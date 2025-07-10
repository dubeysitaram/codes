// 47. Permutations II

/*
Given a collection of numbers, nums, that might contain duplicates, 
return all possible unique permutations in any order.
*/

class Solution {
public:
    void fn(unordered_map<int, int>& mp, int n,vector<vector<int>>& ans, vector<int>& curr) {
        if (curr.size() == n) {
            ans.push_back(curr);
            return;
        }
        for (auto it : unordered_map<int, int>(mp)) {
            int c = it.first;
            curr.push_back(c);
            mp[c]--;
            if (mp[c] == 0)
                mp.erase(c);
            fn(mp, n, ans, curr);
            mp[c]++;
            curr.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        vector<vector<int>> ans;
        vector<int> curr;
        fn(mp, n, ans, curr);
        return ans;
    }
};