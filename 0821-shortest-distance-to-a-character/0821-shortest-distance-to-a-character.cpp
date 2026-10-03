class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(n, 0);
        int i = 0, j = 0;
        while (i < n) {
            if (s[i] == c) {
                while (j != i) {
                    ans[j] = i - j;
                    j++;
                }
                ans[j] = 0;
            }
            i++;
        }
        if (i == n && j != n) {
            int cnt = 0;
            while (j < n) {
                ans[j] = cnt;
                j++;
                cnt++;
            }
        }

        j = n - 1, i = n - 1;
        while (i >= 0) {
            if (s[i] == c) {
                while (i != j) {
                    ans[j] = min(ans[j], j - i);
                    j--;
                }
                ans[j] = 0;
            }
            i--;
        }
        if (i == -1 && j != -1) {
            int cnt = 0;
            while (j >= 0) {
                ans[j] = cnt;
                cnt++;
                j--;
            }
        }
        return ans;
    }
};