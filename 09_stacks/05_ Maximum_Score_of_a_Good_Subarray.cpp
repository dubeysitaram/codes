 // Maximum Score of a Good Subarray

/*
You are given an array of integers nums (0-indexed) and an integer k.

The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1).
 A good subarray is a subarray where i <= k <= j.

Return the maximum possible score of a good subarray.
*/

class Solution {
public:
    vector<int> nseright(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> pseleft(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> nseindex = nseright(nums);
        vector<int> pseindex = pseleft(nums);
        long long ans = 0;
        for (long long i = 0; i < n; i++) {
            long long lower = pseindex[i] + 1;
            long long upper = nseindex[i] - 1;
            if (lower <= k && upper >= k) {
                ans = max(ans, nums[i] * (upper - lower + 1));
            }
        }
        return ans;
    }
};