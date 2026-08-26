class Solution {
public:
    int fun(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j) {
        if (i >= 0 && j >= 0 && grid[i][j] == 1) { // Dead Cell
            return 0;
        }
        if (i == 0 && j == 0) {
            return 1;
        }
        if (i < 0 || j < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int up = fun(grid, dp, i - 1, j);
        int left = fun(grid, dp, i, j - 1);
        return dp[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return fun(grid, dp, m - 1, n - 1);
    }
};

/*
//Simple Recursive Approach
int fun(vector<vector<int>>& grid, int i, int j) {
        if (i >= 0 && j >= 0 && grid[i][j] == 1) { // Dead Cell
            return 0;
        }
        if (i == 0 && j == 0) {
            return 1;
        }
        if (i < 0 || j < 0) {
            return 0;
        }
        int up = fun(grid, i - 1, j);
        int left = fun(grid, i, j - 1);
        return up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return fun(grid, m - 1, n - 1);
    }


*/