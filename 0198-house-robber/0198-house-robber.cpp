class Solution {
public:
    int fun(vector<int>& nums, int i, int n, int free,
            vector<vector<int>>& dp) {
        if (i == n) {
            return 0;
        }
        if (dp[i][free] != -1) {
            return dp[i][free];
        }
        if (free == 0) {
            return fun(nums, i + 1, n, 1, dp);
        }

        // Chori hua hai ghar mein
        int c1 = nums[i] + fun(nums, i + 1, n, 0, dp);
        // Chori nahi hua hai ghar mein
        int c2 = fun(nums, i + 1, n, 1, dp);
        // Max profit
        dp[i][free] = max(c1, c2);
        return dp[i][free];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return fun(nums, 0, n, 1, dp);
    }
};