// 452. Minimum Number of Arrows to Burst Balloons



/*

There are some spherical balloons taped onto a flat wall that represents the XY-plane. 
The balloons are represented as a 2D integer array points 
where points[i] = [xstart, xend] denotes a balloon 
whose horizontal diameter stretches between xstart and xend. 
You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) 
from different points along the x-axis. 
A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. 
There is no limit to the number of arrows that can be shot. 
A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.



*/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(),[](vector<int>& v1, vector<int>& v2) { return v1[1] < v2[1]; });
        long long prev = -1e10;
        long long ct = 0;
        for (int i = 0; i < n; i++) {
            if (points[i][0] >prev) {
                ct++;
                prev = points[i][1];
            }
        }
        return ct;
    }
};