#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> bestPath;
int P;

void dfs(int u, int forwardCost, vector<int>& curPath, vector<char>& vis) {

    if (curPath.size() > bestPath.size() ||
        (curPath.size() == bestPath.size() &&
         lexicographical_compare(curPath.begin(), curPath.end(),
                                 bestPath.begin(), bestPath.end())))
        bestPath = curPath;

    for (auto [v, w] : adj[u]) {
        if (!vis[v] && (forwardCost + w) * 2 <=P) { // still affordable after the return leg?
            vis[v] = 1;
            curPath.push_back(v);
            dfs(v, forwardCost + w, curPath, vis);
            curPath.pop_back();
            vis[v] = 0;
        }
    }
}

void optimalPath(int N, int M, int price, int* source, int* dest, int* weight) {
    P = price;
    adj.assign(N + 1, {});

    for (int i = 0; i < M; ++i) {
        int u = source[i], v = dest[i], w = weight[i];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int i = 1; i <= N; ++i)
        sort(adj[i].begin(), adj[i].end());

    vector<int> curPath{1};
    vector<char> vis(N + 1, 0);
    vis[1] = 1;
    dfs(1, 0, curPath, vis);

    vector<int> route = bestPath; // forward leg
    for (int i = (int)bestPath.size() - 2; i >= 0; --i)
        route.push_back(bestPath[i]);

    for (size_t i = 0; i < route.size(); ++i) {
        cout << route[i];
        if (i + 1 != route.size())
            cout << ' ';
    }
    cout << '\n';
}

int main() {
    int N, M, price;
    cin >> N >> M;
    cin >> price;
    int source[100], dest[100], weight[100];
    for (int i = 0; i < M; i++)
        cin >> source[i] >> dest[i] >> weight[i];
    optimalPath(N, M, price, source, dest, weight);
    return 0;
}
