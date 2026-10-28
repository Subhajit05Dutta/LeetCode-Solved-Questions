class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int i : nums) {
            mpp[i]++;
        }
        vector<vector<int>> ans;
        while (mpp.size() > 0) {
            vector<int> temp;
            for (auto it = mpp.begin(); it != mpp.end();) {
                temp.push_back(it->first);
                it->second--;
                if (it->second == 0) {
                    it = mpp.erase(it);
                } else {
                    ++it;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};