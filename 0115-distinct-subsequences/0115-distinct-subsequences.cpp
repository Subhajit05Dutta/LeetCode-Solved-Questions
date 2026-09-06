class Solution {
public:
    vector<vector<int>> dp;

    int fun(string& s, string& t, int i, int j) {

        if (j == t.size())
            return 1;
        if (i == s.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        // Not take
        int ans = fun(s, t, i + 1, j);

        // Take
        if (s[i] == t[j]) {
            ans += fun(s, t, i + 1, j + 1);
        }
        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        dp.assign(n + 1, vector<int>(m + 1, -1));

        return fun(s, t, 0, 0);
    }
};