class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mpp;
        vector<int> res;
        for (int x : nums) {
            mpp[x]++;
        }
        for (auto &it : mpp) {
            if (it.second == 1) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};