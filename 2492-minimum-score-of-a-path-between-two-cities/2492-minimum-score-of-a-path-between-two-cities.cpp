class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        // Union all connected cities
        for (auto& r : roads) {
            int u = find(r[0]);
            int v = find(r[1]);
            parent[u] = v;
        }
        int ans = 10001;
        // Minimum edge in the component containing city 1
        for (auto& r : roads) {
            if (find(r[0]) == find(1)) {
                ans = min(ans, r[2]);
            }
        }
        return ans;
    }
};