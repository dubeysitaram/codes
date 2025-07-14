const int N = 1e6 + 5;

int parent[N];
int Size[N];

void make(int v) {
    parent[v] = v;
    Size[v] = 1;
}

int find(int v) {
    if (parent[v] == v)
        return v;
    return parent[v] = find(parent[v]);
}

void Union(int a, int b) {
    int c = find(a);
    int d = find(b);
    if (c != d) {
        if (Size[d] > Size[c])
            swap(d, c);
        parent[d] = c;
        Size[c] += Size[d];
    }
}

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    make(i * n + j);
                }
            }
        }
        int X[4] = {1, 0, -1, 0};
        int Y[4] = {0, 1, 0, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    for (int k = 0; k < 4; k++) {
                        int new_x = i + X[k];
                        int new_y = j + Y[k];
                        if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && grid[new_x][new_y]) {
                            int p = find(new_x * n + new_y);
                            Union(i * n + j, new_x * n + new_y);
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    int temp_size = 0;
                    set<int> seen_parents;
                    for (int k = 0; k < 4; k++) {
                        int new_x = i + X[k];
                        int new_y = j + Y[k];
                        if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && grid[new_x][new_y]) {
                            int p = find(new_x * n + new_y);
                            if (seen_parents.find(p) == seen_parents.end()) {
                                temp_size += Size[p];
                                seen_parents.insert(p);
                            }
                        }
                    }
                    ans = max(temp_size + 1, ans);
                } else {
                    int p = find(i * n + j);
                    ans = max(ans, Size[p]);
                }
            }
        }
        return ans;
    }
};