class Solution {
    vector<int> ans;

public:
    void dfs(int root, vector<vector<int>>& g, vector<int>& parent, string& s,
             vector<int> recentPar) {
        int i = s[root] - 'a';
        if (recentPar[i] != -1)
            parent[root] = recentPar[i]; // if the recent par char node value is
                                         // not -1 then there is an acenstor
                                         // exists which has same char value
        recentPar[i] = root; // update the recent parent for the current char
                             // with current node
        for (auto n : g[root])
            dfs(n, g, parent, s, recentPar);
        if (parent[root] >= 0)
            ans[parent[root]] += ans[root]; // while returning collect the tree
                                            // size to its parent
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        ans.resize(parent.size(), 1);
        vector<int> recentParent(26, -1);
        vector<vector<int>> g(parent.size());
        for (int i = 1; i < parent.size(); ++i)
            g[parent[i]].push_back(i); // create graph from the parent mapping
        dfs(0, g, parent, s, recentParent); // do dfs from root to leaf node to
                                            // check parent updates
        return ans;
    }
};