class Solution {
public:
    // Memoization(Bottom-Up Approach)
    int fun(vector<int>& nums, vector<vector<int>>& dp, int target, int i) {
        if (i == 0) {
            if (target == 0 && nums[0] == 0) {
                return 2;
            } else if (target == 0 || nums[0] == target) {
                return 1;
            }
            return 0;
        }
        if (dp[i][target] != -1) {
            return dp[i][target];
        }
        int not_take = fun(nums, dp, target, i - 1);
        int take = 0;
        if (nums[i] <= target) {
            take = fun(nums, dp, target - nums[i], i - 1);
        }
        dp[i][target] = take + not_take;
        return dp[i][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totsum = 0;
        for (int i = 0; i < n; i++) {
            totsum += nums[i];
        }
        int diff = totsum - target;

        if (diff < 0 || diff % 2 != 0) {
            return 0;
        }
        int sum = diff / 2;
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
        // Base Case
        if (nums[0] == 0) {
            dp[0][0] = 2;
        } else {
            dp[0][0] = 1;
        }

        if (nums[0] != 0 && nums[0] <= sum) {
            dp[0][nums[0]] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= sum; j++) {
                int not_take = dp[i - 1][j];
                int take = 0;
                if (nums[i] <= j) {
                    take = dp[i - 1][j - nums[i]];
                }
                dp[i][j] = take + not_take;
            }
        }
        return dp[n - 1][sum];
    }
};

/*
    //Memoization(Top-Down Approach)

    int fun(vector<int>& nums, vector<vector<int>>& dp, int target, int i) {
        if (i == 0) {
            if (target == 0 && nums[0] == 0) {
                return 2;
            } else if (target == 0 || nums[0] == target) {
                return 1;
            }
            return 0;
        }
        if (dp[i][target] != -1) {
            return dp[i][target];
        }
        int not_take = fun(nums, dp, target, i - 1);
        int take = 0;
        if (nums[i] <= target) {
            take = fun(nums, dp, target - nums[i], i - 1);
        }
        dp[i][target] = take + not_take;
        return dp[i][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totsum = 0;
        for (int i = 0; i < n; i++) {
            totsum += nums[i];
        }
        int diff = totsum - target;

        if (diff < 0 || diff % 2 != 0) {
            return 0;
        }
        int sum = diff / 2;
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return fun(nums, dp, sum, n - 1);
    }
*/