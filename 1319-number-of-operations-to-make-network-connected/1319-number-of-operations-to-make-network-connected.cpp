class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void unionset(int x, int y) {
        int x_par = find(x);
        int y_par = find(y);
        if (x_par == y_par)
            return;
        if (rank[x_par] > rank[y_par]) {
            parent[y_par] = x_par;
        } else if (rank[x_par] < rank[y_par]) {
            parent[x_par] = y_par;
        } else {
            parent[x_par] = y_par;
            rank[y_par]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        int component = n;
        int e = connections.size();
        if (e < n - 1) {
            return -1;
        }
        for (int i = 0; i < e; i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            if (find(u) == find(v)) {
                continue;
            } else {
                unionset(u, v);
                component--;
            }
        }
        return component - 1;
    }
};