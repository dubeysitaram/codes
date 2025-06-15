/*

The median is the middle value in an ordered integer list. 
If the size of the list is even, 
there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far.
 Answers within 10-5 of the actual answer will be accepted.



*/

class MedianFinder {
public:
    multiset<int> s1, s2;
    MedianFinder() {}

    void addNum(int num) {
        // insert into appropriate half
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
};
