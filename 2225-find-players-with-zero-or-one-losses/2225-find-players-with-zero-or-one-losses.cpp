class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, pair<int, int>> mpp;
        for (int i = 0; i < matches.size(); i++) {
            mpp[matches[i][0]].first++;
            mpp[matches[i][1]].second++;
        }

        vector<vector<int>> ans(2);
        for (auto& it : mpp) {
            if (it.second.second == 0) {
                ans[0].push_back(it.first);
            }
            if (it.second.second == 1) {
                ans[1].push_back(it.first);
            }
        }
        return ans;
    }
};