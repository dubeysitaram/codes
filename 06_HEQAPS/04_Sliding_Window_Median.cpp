/*The median is the middle value in an ordered integer list. 
If the size of the list is even, there is no middle value. 
So the median is the mean of the two middle values.

For examples, if arr = [2,3,4], the median is 3.
For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
You are given an integer array nums and an integer k. 
There is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.

Constraints:

1 <= k <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
*/

class MedianFinder {
public:
    multiset<double> s1, s2;
    MedianFinder() {}

    void addNum(double num) {
        // insert doubleo appropriate half
        if (s1.empty() || num <= *prev(s1.end()))
            s1.insert(num);
        else
            s2.insert(num);

        // rebalance
        if (s1.size() > s2.size() + 1) {
            auto it = prev(s1.end());
            s2.insert(*it);
            s1.erase(it);
        } else if (s2.size() > s1.size()) {
            auto it = s2.begin();
            s1.insert(*it);
            s2.erase(it);
        }
    }

    double findMedian() {
        int n = s1.size() + s2.size();
        double ans;
        if (n % 2)
            ans = *prev(s1.end());
        else
            ans = (*prev(s1.end()) + *s2.begin()) / 2.0;
        ans = round(ans * 1e5) / 1e5;
        return ans;
    }
    void remove(double x) {
        if (s1.find(x) != s1.end())
            s1.erase(s1.find(x));
        else {
            s2.erase(s2.find(x));
        }
    }
};

class Solution {
public:
    MedianFinder mh; /// creating the instance of the above class 
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        double n = nums.size();
        for (double i = 0; i < k; i++) {
            mh.addNum(nums[i]);
        }
        ans.push_back(mh.findMedian());
        if(k==n)return ans;
        for(double i=k;i<n;i++){
            mh.remove(nums[i-k]);
            mh.addNum(nums[i]);
            ans.push_back(mh.findMedian());
        }
        return ans;
    }
};