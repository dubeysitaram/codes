// 3097. Shortest Subarray With OR at Least K II
/*

You are given an array nums of non-negative integers and an integer k.

An array is called special if the bitwise OR of all of its elements is at least k.

Return the length of the shortest special non-empty subarray of nums, or return -1 if no special subarray exists.



*/



class Solution {
public:
    long long ans = LLONG_MAX;

    void add(vector<long long>& v, long long x) {
        for (int i = 0; i < 32; i++) {
            if ((x >> i) & 1) {
                v[i]++;
            }
        }
    }

    long long rem(vector<long long>& v, long long x, long long res) {
        for (int i = 0; i < 32; i++) {
            if ((x >> i) & 1) {
                v[i]--;
                if (v[i] == 0) {
                    res &= ~(1LL << i);
                }
            }
        }
        return res;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> v(32, 0);
        long long res = 0;
        int i = 0;

        for (int j = 0; j < n; j++) {
            res |= nums[j];
            add(v, nums[j]);
            while (i <= j && res >= k) {
                ans = min(ans, (long long)j - i + 1);
                res = rem(v, nums[i], res);
                i++;
            }
        }

        return ans == LLONG_MAX ? -1 : (int)ans;
    }
};
