class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int i : nums) {
            mpp[i]++;
        }
        int ans = 0;
        for (auto& it : mpp) {
            if (it.second % k == 0) {
                ans += (it.first * it.second);
            }
        }
        return ans;
    }
};