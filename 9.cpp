class Solution {
public:
    const long long INF = LLONG_MAX / 4;

    bool isPossible(int thresh, vector<vector<pair<int, int>>>& adj, vector<bool>& online, long long k, int n) {
        vector<long long> dist(n, INF);
        set<pair<long long, int>> st;
        dist[0] = 0;
        st.insert({0, 0});

        while (!st.empty()) {
            auto [d, u] = *st.begin();
            st.erase(st.begin());
            if (d > dist[u])
                continue;

            for (auto& [v, w] : adj[u]) {
                ispossible
                if (w < thresh || !online[v])
                    continue;
                long long nd = d + w;
                if (nd < dist[v]) {
                    st.erase({dist[v], v});
                    dist[v] = nd;
                    st.insert({nd, v});
                }
            }
        }

        return dist[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges)
            adj[e[0]].push_back({e[1], e[2]});

        int lo = -1, hi = 1e9 + 10;

        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if (isPossible(mid, adj, online, k, n))
                lo = mid;
            else
                hi = mid;
        }
        cout << lo << endl;
        return isPossible(hi, adj, online, k, n) ? hi : lo;
    }
};
