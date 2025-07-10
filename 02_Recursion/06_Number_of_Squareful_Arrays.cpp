// 06_Number_of_Squareful_Arrays.cpp

/*
// conncept of permutation 2

An array is squareful if the sum of every pair of adjacent elements is a perfect square.

Given an integer array nums, return the number of permutations of nums that are squareful.

Two permutations perm1 and perm2 are different 
if there is some index i such that perm1[i] != perm2[i].
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        int root = sqrt(num);
        return root * root == num;
    }

    void fn(int prev, unordered_map<int, int>& mp, vector<int>& nums, int n,int& ans, vector<int>& curr) {
        if (curr.size() == n) {
            ans++;
            return;
        }
        if (mp.empty()) {
            return;
        }
        for (auto it : unordered_map<int, int>(mp)) {
            int c = it.first;
            int x = c + prev;
            if (isPerfectSquare(x)) {
                curr.push_back(c);
                mp[c]--;
                if (mp[c] == 0)
                    mp.erase(c);
                fn(c, mp, nums, n, ans, curr);
                mp[c]++;
                curr.pop_back();
            }
        }
    }

    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        int ans = 0;
        vector<int> curr;
        for (auto it : unordered_map<int, int>(mp)) {
            int num = it.first;
            curr.push_back(num);
            mp[num]--;
            if (mp[num] == 0)
                mp.erase(num);
            fn(num, mp, nums, n, ans, curr);
            mp[num]++;
            curr.pop_back();
        }
        return ans;
    }
};
