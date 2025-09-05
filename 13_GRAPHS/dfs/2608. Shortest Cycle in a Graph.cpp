/*
2608. Shortest Cycle in a Graph

There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1.
The edges in the graph are represented by a given 2D integer array edges, where edges[i] = [ui, vi]
denotes an edge between vertex ui and vertex vi.
Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

Return the length of the shortest cycle in the graph. If no cycle exists, return -1.

A cycle is a path that starts and ends at the same node, and each edge in the path is used only once.


*/

// concept length of the cycle in undirected graph is equal to if a child v of node u 
// is already visited and not the parent then
// legth of the cycle if cycle_len = level[u]+level[v]+1;
// and we have to apply the bfs for each node of component of a graph in oreder to find the min length of the cycle


class Solution
{
  public:
    int ans = INT_MAX;

    void bfs(int node, vector<vector<int>> &g, int n)
    {
        vector<int> vis(n, 0); vector<int>level(n, 0);
        queue<pair<int, int>> q;
        q.push({node, -1});
        vis[node] = 1;
        level[node] = 0;
        while (!q.empty())
        {
            auto [curr, parent] = q.front();
            q.pop();
            for (auto it : g[curr])
            {
                if (it == parent)
                    continue;
                if (vis[it])
                {
                    ans = min(ans, level[curr] + level[it] + 1);
                }
                else
                {
                    vis[it] = 1;
                    level[it] = level[curr] + 1;
                    q.push({it, curr});
                }
            }
        }
    }

    int findShortestCycle(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> g(n);
        for (int i = 0; i < edges.size(); i++)
        {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n, 0), level(n);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                vector<int> component;
                component.push_back(i);
                queue<pair<int, int>> q;
                q.push({i, -1});
                vis[i] = 1;
                while (!q.empty())
                {
                    auto it = q.front();
                    q.pop();
                    int node = it.first;
                    int par = it.second;
                    component.push_back(node);
                    for (auto child : g[node])
                    {
                        if (child == par)
                            continue;
                        if (vis[child])
                            continue;
                        q.push({child, node});
                        vis[child] = 1;
                    }
                }
                for (auto it : component)
                {
                    bfs(it, g, n);
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};
