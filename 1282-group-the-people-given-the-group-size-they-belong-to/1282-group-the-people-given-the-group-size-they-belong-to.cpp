class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> v(n + 1);
        for (int i = 0; i < n; i++) {
            v[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for (int i = 1; i <= n; i++) {
            int j = 0;
            for (int k = 0; k < v[i].size() / i; k++) {
                vector<int> temp;
                for (int z = 0; z < i; z++) {
                    temp.push_back(v[i][j++]);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};