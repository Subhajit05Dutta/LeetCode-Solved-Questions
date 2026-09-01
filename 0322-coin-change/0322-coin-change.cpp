class Solution {
public:
    // Memoization(Bottom-Up)
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int T = 0; T <= amount; T++) {
            if (T % coins[0] == 0) {
                dp[0][T] = T / coins[0];
            }
            else{
                dp[0][T]=1e9;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int T = 0; T <= amount; T++) {
                int not_take = dp[i - 1][T];
                int take = 1e9;
                if (coins[i] <= T) {
                    take = 1 + dp[i][T - coins[i]];
                }

                dp[i][T] = min(take, not_take);
            }
        }
        if (dp[n - 1][amount] >= 1e9) {
            return -1;
        }
        return dp[n - 1][amount];
    }
};

/*

    //Recursive Approach
    int fun(vector<int>& coins, int target, int i) {
        if (i == 0) {
            if (target == 0) {
                return 0;
            } else if (target % coins[0] == 0) {
                return target / coins[i];
            } else {
                return 1e9;
            }
        }
        int not_take = 0 + fun(coins, target, i - 1);
        int take = 1e9;
        if (coins[i] <= target) {
            take = 1 + fun(coins, target - coins[i], i);
        }
        return min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = fun(coins, amount, n - 1);
        return ans >= 1e9 ? -1 : ans;
    }


    //Memoization(Top-Down)
     int fun(vector<int>& coins, vector<vector<int>>& dp, int target, int i) {
        if (i == 0) {
            if (target == 0) {
                return 0;
            } else if (target % coins[0] == 0) {
                return target / coins[i];
            } else {
                return 1e9;
            }
        }

        if (dp[i][target] != -1) {
            return dp[i][target];
        }

        int not_take = 0 + fun(coins, dp, target, i - 1);

        int take = 1e9;
        if (coins[i] <= target) {
            take = 1 + fun(coins, dp, target - coins[i], i);
        }

        return dp[i][target] = min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = fun(coins, dp, amount, n - 1);
        return ans >= 1e9 ? -1 : ans;
    }
*/