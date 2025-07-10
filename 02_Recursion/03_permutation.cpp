// LC 46. Permutations
/*

Given an array nums of distinct integers, 
return all the possible permutations. You can return the answer in any order.
*/
// https://www.geeksforgeeks.org/dsa/write-a-c-program-to-print-all-permutations-of-a-given-string/


class Solution {
public:
    void fn(int index,vector<int>& nums,vector<vector<int>>&result ){
        if(index==nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i = index;i<nums.size();i++){
           swap(nums[i],nums[index]);
           fn(index+1,nums,result);
           swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>>result;
      fn(0,nums,result);
      return result;
    }
};

//------------------------------------------MY CODE -------------------------------------------------------->

class Solution {
public:
    vector<vector<int>> v;
    void fn(vector<int>& nums, vector<int>& vis, vector<int>& curr, int n,int run) {
        if (run > n) {
            return;
        }
        if (curr.size() == n) {
            v.push_back(curr);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                curr.push_back(nums[i]);
                vis[i] = 1;
                fn(nums, vis, curr, n, run + 1);
                vis[i] = 0;
                curr.pop_back();
                fn(nums, vis, curr, n, run + 1);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n, 0);
        vector<int> curr;
        fn(nums, vis, curr, n, 0);
        return v;
    }
};