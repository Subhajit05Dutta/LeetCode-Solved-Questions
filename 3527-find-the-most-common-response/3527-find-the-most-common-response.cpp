class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> mpp;
        for (int i = 0; i < responses.size(); i++) {
            set<string> day(responses[i].begin(), responses[i].end());

            for (auto& it : day) {
                mpp[it]++;
            }
        }
        int high = 0;
        string ans = "";
        for (auto& it : mpp) {
            if (it.second > high ||
                (it.second == high && (ans.empty() || it.first < ans))) {
                high = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};