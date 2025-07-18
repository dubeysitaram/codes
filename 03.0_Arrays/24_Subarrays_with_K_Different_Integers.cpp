// Leetcode 992. Subarrays with K Different Integers
/*

Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

*/

// yaha count find karna hai kahin length find karne ke liye bhi bol sakta hai 

class Solution {
public:
   
    int atMostK(vector<int>& nums, int k){
        unordered_map<int,int>mp;
        int n = nums.size();
        int i=0;int j=0;int ct=0;
        while(j<n){
            mp[nums[j]]++;

            while(mp.size()>k){
              mp[nums[i]]--;
              if(mp[nums[i]]==0)mp.erase(nums[i]);
              i++;
            }
            ct+=j-i+1;
            j++;
        }
        return ct;
    }
  

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums,k)-atMostK(nums,k-1);
    }
};

//GFG.  Longest subarray with Atmost two distinct integers

/*
Given an array arr[] consisting of positive integers, 
your task is to find the length of the longest subarray that contains 
at most two distinct integers.
*/


int atMostK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=1;
        unordered_map<int, int> freq;
        int i = 0, j = 0, count = 0;

        while (j < n) {
            if (freq[nums[j]] == 0)
                k--;
            freq[nums[j]]++;

            while (k < 0) {
                freq[nums[i]]--;
                if (freq[nums[i]] == 0)
                    k++;
                i++;
            }

            ans=max(ans,j-i+1);
            j++;
        }

        return ans;
}

int totalElements(vector<int> &arr) {


        int i=0;int j=0;int n = arr.size();int ans=0;
        map<int,int>mp;
        while(j<n){
             mp[arr[j]]++;
             while(mp.size()>2){
                 mp[arr[i]]--;
                 if(mp[arr[i]]==0)mp.erase(arr[i]);
                 i++;
             }
             ans =max(ans,j-i+1);
             j++;
    }
    return ans;// same code written in atMostK
     // or
    return atMostK(arr,2); 
}


// Q3 GFG Longest Substring with K Uniques

/*
You are given a string s consisting only lowercase alphabets and an integer k.
Your task is to find the length of the longest substring 
that contains exactly k distinct characters.
Note : If no such substring exists, return -1. 

*/
class Solution {
  public:
      int atMostK(string &nums, int k){
        unordered_map<char,int>mp;
        int n = nums.size();
        int i=0;int j=0;
        int ans=0;
        while(j<n){
            mp[nums[j]]++;

            while(mp.size()>k){
              mp[nums[i]]--;
              if(mp[nums[i]]==0)mp.erase(nums[i]);
              i++;
            }
            if(mp.size()==k)
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
    int longestKSubstr(string &s, int k) {
        // code here
        int x = atMostK(s,k);
        return (x==0)?-1:x;
        
    }
};