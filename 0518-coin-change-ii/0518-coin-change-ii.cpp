class Solution {
public:
    int fun(int amount, vector<vector<int>>& dp, vector<int>& coins, int i) {
        if (i == 0) {
            return (amount % coins[0] == 0);
        }
        if (dp[i][amount] != -1) {
            return dp[i][amount];
        }
        int not_take = fun(amount, dp, coins, i - 1);
        int take = 0;
        if (coins[i] <= amount) {
            take = fun(amount - coins[i], dp, coins, i);
        }
        return dp[i][amount] = take + not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return fun(amount, dp, coins, n - 1);
    }
};

/*

    //Recursive Approach
     int fun(int amount, vector<int>& coins, int i) {
        if (i == 0) {
            return (amount % coins[0] == 0);
        }
        int not_take = fun(amount, coins, i - 1);
        int take = 0;
        if (coins[i] <= amount) {
            take = fun(amount - coins[i], coins, i);
        }
        return take + not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return fun(amount, coins, n - 1);
    }

*/