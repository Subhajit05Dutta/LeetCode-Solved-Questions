class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        unordered_map<int, int> dp;
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int& a : nums) {
            res = max(res, dp[a + 1] = dp[a] + 1);
            res = max(res, dp[a] = dp[a - 1] + 1);
        }
        return res;
    }
};