class Solution {
public:
    void dfs(int u, vector<bool>& vis, vector<vector<int>>& adj,
             vector<int>& comp) {
        vis[u] = true;
        comp.push_back(u);
        for (int it : adj[u]) {
            if (vis[it] == false) {
                dfs(it, vis, adj, comp);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n, false);
        int ans = 0;

        vector<int> comp;
        for (int i = 0; i < n; i++) {
            if (vis[i] == false) {
                vector<int> comp;
                dfs(i, vis, adj, comp);
                bool isComplete = true;

                for (int u : comp) {
                    if (adj[u].size() != comp.size() - 1) {
                        isComplete = false;
                        break;
                    }
                }
                if (isComplete == true) {
                    ans++;
                }
            }
        }
        return ans;
    }
};