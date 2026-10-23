class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int i : nums) {
            mpp[i]++;
        }
        int pair = 0;
        int left = 0;
        for (auto& it : mpp) {

            pair += (it.second / 2);
            left += it.second % 2;
        }
        return {pair, left};
    }
};