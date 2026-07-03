class Solution {
public:
    typedef long long ll;
    typedef pair<long long, int> p;
    bool check(int mid, int n, ll k,
               unordered_map<int, vector<vector<int>>>& adj) {
        vector<long long> res(n, LLONG_MAX);
        priority_queue<p, vector<p>, greater<p>> pq;
        res[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            ll d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (d > k) {
                return false;
            }
            if (node == n - 1) {
                return true;
            }
            if (res[node] < d) {
                continue;
            }
            for (auto& it : adj[node]) {
                int neighbour = it[0];
                int cost = it[1];
                if (cost < mid) {
                    continue;
                }
                if (d + cost < res[neighbour]) {
                    res[neighbour] = d + cost;
                    pq.push({d + cost, neighbour});
                }
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        int n = online.size();
        unordered_map<int, vector<vector<int>>> adj;
        int l = INT_MAX;
        int r = 0;
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            // If either of the node is offline
            if (!online[u] || !online[v]) {
                continue;
            }
            adj[u].push_back({v, wt});
            l = min(l, wt);
            r = max(r, wt);
        }
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid, n, k, adj)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};