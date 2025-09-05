/*
2360. Longest Cycle in a Graph

You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n,
indicating that there is a directed edge from node i to node edges[i].
If there is no outgoing edge from node i, then edges[i] == -1.

Return the length of the longest cycle in the graph. If no cycle exists, return -1.

A cycle is a path that starts and ends at the same node.

*/

// here in directed graph in order to find the cycle exist or not we have to apply dfs in undirected graph cycle can also be detected via
// bfs , also we need to run the dfs only once for a node of a component beacuse it is a directed graph
// and in directed graph if you carefully see the cycle length will be length[v]-length[u]+1;
// where u is node whose choild v is already pathvisited and visited

class Solution {
public:
    int ans = -1;

    void dfs(int node, vector<int> g[], vector<int>& vis, vector<int>& pathVis, vector<int>& depth) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (int nbr : g[node]) {
            if (!vis[nbr]) {
                depth[nbr] = depth[node] + 1;
                dfs(nbr, g, vis, pathVis, depth);
            } else if (pathVis[nbr]) {
                int cycleLength = depth[node] - depth[nbr] + 1;
                ans = max(ans, cycleLength);
            }
        }

        pathVis[node] = 0;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> g[n];

        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) {
                g[i].push_back(edges[i]);
            }
        }

        vector<int> vis(n, 0), pathVis(n, 0), depth(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, g, vis, pathVis, depth);
            }
        }

        return ans;
    }
};
