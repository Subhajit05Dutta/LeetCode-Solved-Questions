class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 1];
        for (auto& it : times) {
            int src = it[0];
            int des = it[1];
            int wt = it[2];
            adj[src].push_back({des, wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> time(n + 1, 1e9);
        time[k] = 0;
        //{Time,Node}
        pq.push({0, k});
        while (!pq.empty()) {
            int t = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (t > time[node]) {
                continue;
            }
            for (auto& it : adj[node]) {
                int adjnode = it.first;
                int dist = it.second;
                if (dist + t < time[adjnode]) {
                    time[adjnode] = dist + t;
                    pq.push({dist + t, adjnode});
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, time[i]);
        }
        return ans == 1e9 ? -1 : ans;
    }
};