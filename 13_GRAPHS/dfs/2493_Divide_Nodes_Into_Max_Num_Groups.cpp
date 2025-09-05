/*
2493_Divide_Nodes_Into_Max_Num_Groups.cpp
You are given a positive integer n representing the number of nodes in an undirected graph.
 The nodes are labeled from 1 to n.

You are also given a 2D integer array edges, where edges[i] = [ai, bi]
indicates that there is a bidirectional edge between nodes ai and bi. Notice that the given graph may be disconnected.

Divide the nodes of the graph into m groups (1-indexed) such that:

Each node in the graph belongs to exactly one group.
For every pair of nodes in the graph that are connected by an edge [ai, bi],
if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.
Return the maximum number of groups (i.e., maximum m) into which you can divide the nodes.
Return -1 if it is impossible to group the nodes with the given conditions.
*/

// yaha ye concept sikhne ko mila ki ek graph mai agar diffrent nodes se bfs lagaoge to diffrent 

/*

Key Observations and Thought Process
Problem Analysis:

Goal: Assign nodes to groups such that adjacent nodes are in consecutive groups. Maximize the number of groups.
Key Constraint: If two nodes are connected, their groups must differ by exactly 1. This implies the graph must allow a "layered" grouping.
Bipartiteness Check:

Why? If the graph has an odd-length cycle (non-bipartite), it’s impossible to assign groups. For example:
A triangle (A-B-C-A) forces conflicting group assignments (A=1 → B=2 → C=3 → A=4, but A and C are adjacent, requiring |4-3|=1 → impossible).
Action: Check if all graph components are bipartite. If any component is non-bipartite, return -1.
Max Groups in a Bipartite Component:

Intuition: The maximum groups for a bipartite component is determined by the longest shortest path (diameter) between any two nodes.
Example: In a chain A-B-C-D, the longest path is from A to D (3 edges → 4 groups).
BFS Insight: For each node, BFS computes the shortest path to all others. The maximum depth (distance) during BFS gives the longest path starting from that node.
Action: For each component, run BFS from every node and track the maximum depth. The component’s contribution is max_depth + 1.
Component Independence:

Disconnected components are processed separately. Their group counts are additive.
Example: Two disjoint chains A-B-C (3 groups) and D-E (2 groups) → total groups = 3 + 2 = 5.

*/


class Solution
{
  public:
    int bfs(int start, vector<vector<int>> &g, vector<int> &visited)
    {
        int level = 0;
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        while (!q.empty())
        {
            int sz = q.size();
            level++;
            while (sz--)
            {
                int node = q.front(); q.pop();
                for (int nei : g[node])
                {
                    if (!visited[nei])
                    {
                        visited[nei] = 1;
                        q.push(nei);
                    }
                }
            }
        }
        return level;
    }

    bool isBipartite(int node, vector<vector<int>> &g, vector<int> &color)
    {
        queue<int> q;
        q.push(node);
        color[node] = 0;
        while (!q.empty())
        {
            int curr = q.front(); q.pop();
            for (int nei : g[curr])
            {
                if (color[nei] == -1)
                {
                    color[nei] = 1 - color[curr];
                    q.push(nei);
                }
                else if (color[nei] == color[curr])
                {
                    return false;
                }
            }
        }
        return true;
    }

    int magnificentSets(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> g(n);
        for (auto &e : edges)
        {
            g[e[0] - 1].push_back(e[1] - 1);
            g[e[1] - 1].push_back(e[0] - 1);
        }
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1 && !isBipartite(i, g, color))
            {
                return -1;
            }
        }
        int ans = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                // Get all nodes in the component
                vector<int> component;
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while (!q.empty())
                {
                    int curr = q.front(); q.pop();
                    component.push_back(curr);
                    for (int nei : g[curr])
                    {
                        if (!visited[nei])
                        {
                            visited[nei] = true;
                            q.push(nei);
                        }
                    }
                }
                // Try each node in component as BFS root and take max depth
                int maxDepth = 0;
                for (int node : component)
                {
                    vector<int> seen(n, 0);
                    maxDepth = max(maxDepth, bfs(node, g, seen));
                }
                ans += maxDepth;
            }
        }
        return ans;
    }
};
