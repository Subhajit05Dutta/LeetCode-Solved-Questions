class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++) {
            int take = nums[i];
            if (i > 1) {
                take += prev2;
            }
            int not_take = 0 + prev;

            int curr = max(take, not_take);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    /*
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
            // Initally all are assigned with -1
            vector<vector<int>> dp(n, vector<int>(2, -1));
            return fun(nums, 0, n, 1, dp);
        }
        */

    /*
    //Simple Recursive Approach
        T.C -->O(2^N)
        S.C -->O(N)

    int fun(vector<int>& nums, int i) {
        if (i == 0) {
            return nums[0];
        }
        if (i < 0) {
            return 0;
        }
        //If we pick that house then we can't pick the next adjacent house
    that's why we move to (i-2) int pick = nums[i] + fun(nums, i - 2);

        //If we do not pick that house then we can pick the next adjacent house
    that's why we move to (i-1) int not_pick = 0 + fun(nums, i - 1);

        return max(pick, not_pick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        return fun(nums, n - 1);
    }
    */
};