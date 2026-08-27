class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }
        // Calculate from second-last row to top
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                int d = triangle[i][j] + dp[i + 1][j];
                int dg = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(d, dg);
            }
        }

        return dp[0][0];
    }
};

/*
//Recursive Approach
    int fun(vector<vector<int>>& triangle, int n, int i, int j) {
        if (i == n - 1) {
            return triangle[n - 1][j];
        }
        int down = triangle[i][j] + fun(triangle, n, i + 1, j);
        int diagonal = triangle[i][j] + fun(triangle, n, i + 1, j + 1);
        return min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        return fun(triangle, n, 0, 0);
    }


//Memoization(Top-Down Approach)
    int fun(vector<vector<int>>& triangle, int n, int i, int j,
            vector<vector<int>>& dp) {
        if (i == n - 1) {
            return triangle[n - 1][j];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int down = triangle[i][j] + fun(triangle, n, i + 1, j, dp);
        int diagonal = triangle[i][j] + fun(triangle, n, i + 1, j + 1, dp);
        return dp[i][j] = min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return fun(triangle, n, 0, 0, dp);
    }
*/