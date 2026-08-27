class Solution {
public:
    int fun(vector<vector<int>>& dp, vector<vector<int>>& grid, int m, int n) {
        if (m == 0 && n == 0) {
            return grid[0][0];
        } else if (m < 0 || n < 0) {
            return INT_MAX;
        }
        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        int up = fun(dp, grid, m - 1, n);
        int left = fun(dp, grid, m, n - 1);
        dp[m][n] = grid[m][n] + min(up, left);
        return dp[m][n];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return fun(dp, grid, m - 1, n - 1);
    }
};

/*

//Simple Recursive Approach
    int fun(vector<vector<int>>& grid, int m, int n) {
        if (m == 0 && n == 0) {
            return grid[0][0];
        } else if (m < 0 || n < 0) {
            return INT_MAX;
        }
        int up = fun(grid, m - 1, n);
        int left = fun(grid, m, n - 1);
        return grid[m][n] + min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return fun(grid, m - 1, n - 1);
    }

*/