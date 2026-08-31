class Solution {
public:
    int fun(vector<int>& coins,vector<vector<int>>&dp, int target, int i) {
        if (i == 0) {
            if (target == 0) {
                return 0;
            } else if (target % coins[0] == 0) {
                return target / coins[i];
            } else {
                return 1e9;
            }
        }

        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int not_take = 0 + fun(coins, dp,target, i - 1);
        int take = 1e9;
        if (coins[i] <= target) {
            take = 1 + fun(coins,dp, target - coins[i], i);
        }
        return dp[i][target]=min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = fun(coins,dp, amount, n - 1);
        return ans >= 1e9 ? -1 : ans;
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

*/