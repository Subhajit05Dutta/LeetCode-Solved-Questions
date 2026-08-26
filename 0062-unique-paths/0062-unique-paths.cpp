class Solution {
public:
    int fun(vector<vector<int>>& dp, int i, int j) {
        if (i == 0 && j == 0) {
            return 1;
        }
        if (i < 0 || j < 0) { // out of boundary
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int up = fun(dp, i - 1, j);
        int left = fun(dp, i, j - 1);
        return dp[i][j] = up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return fun(dp, m - 1, n - 1);
    }
};

/*
//Recursive Approach
int fun(int i, int j) {
        if (i == 0 && j == 0) {
            return 1;
        }
        if (i < 0 || j < 0) { // out of boundary
            return 0;
        }
        int up = fun(i - 1, j);
        int left = fun(i, j - 1);
        return up + left;
    }
    int uniquePaths(int m, int n) {
        return fun(m-1, n-1);
    }

*/