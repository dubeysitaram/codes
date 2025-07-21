/*_Min_Cost_to_Connect_All_Points.cpp


You are given an array points representing integer coordinates of some points on a 2D-plane,
where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: 
|xi - xj| + |yi - yj|, 
where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. 
All points are connected if there is exactly one simple path between any two points.

Constraints:

1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.


 */


//  use concept of minimum spanning tree 
class Solution {
public:

vector<int> parent, Size;

void make(int v) {
    parent[v] = v;
    Size[v] = 1;
}

int fn(int v) {
    if (parent[v] == v)
        return v;
    return parent[v] = fn(parent[v]);
}

void Union(int a, int b) {
    int c = fn(a);
    int d = fn(b);
    if (c != d) {
        if (Size[d] > Size[c])
            swap(d, c);
        parent[d] = c;
        Size[c] += Size[d];
    }
}

int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    parent.resize(n);
    Size.resize(n);

    vector<pair<int, pair<int, int>>> dis;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x = abs(points[i][0] - points[j][0]) +
                    abs(points[i][1] - points[j][1]);
            dis.push_back({x, {i, j}});
        }
    }

    sort(dis.begin(), dis.end());

    for (int i = 0; i < n; i++) {
        make(i);
    }

    int ans = 0;
    for (auto& d : dis) {
        int a = d.second.first;
        int b = d.second.second;
        int val = d.first;
        if (fn(a) != fn(b)) {
            Union(a, b);
            ans += val;
        }
    }
    return ans;
}

};