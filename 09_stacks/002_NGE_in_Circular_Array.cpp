// Next Greater Element in Circular Array
/*
Given a circular integer array arr[],
the task is to determine the next greater element (NGE) for each element in the array.

The next greater element of an element arr[i] is the first element that is greater than arr[i]
when traversing circularly. If no such element exists, return -1 for that position.

Circular Property:

Since the array is circular, after reaching the last element,
the search continues from the beginning until we have looked at all elements once.


*/
class Solution {
public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        vector<int>nums = arr;
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            nums.push_back(arr[i]);
        }
        vector<int>nge(nums.size(), -1);
        stack<int>st;
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                nge[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nge[i] != -1) {
                nge[i] = nums[nge[i]];
            }
        }
        return nge;
    }
};