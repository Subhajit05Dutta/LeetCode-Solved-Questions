class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> pos, digit;

        // Store non-zero digits and their positions
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int m = digit.size();

        // Prefix sum of digits
        vector<long long> preSum(m + 1, 0);
        for (int i = 0; i < m; i++) {
            preSum[i + 1] = preSum[i] + digit[i];
        }

        // Prefix concatenated number
        vector<long long> preNum(m + 1, 0);
        for (int i = 0; i < m; i++) {
            preNum[i + 1] = (preNum[i] * 10 + digit[i]) % MOD;
        }

        // Powers of 10
        vector<long long> power(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            power[i] = (power[i - 1] * 10) % MOD;
        }

        vector<int> ans;

        for (auto& q : queries) {
            int l = q[0], r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            // No non-zero digit in the range
            if (L > R) {
                ans.push_back(0);
                continue;
            }

            long long sum = preSum[R + 1] - preSum[L];

            long long num =
                (preNum[R + 1] - (preNum[L] * power[R - L + 1]) % MOD + MOD) %
                MOD;

            ans.push_back((num * sum) % MOD);
        }

        return ans;
    }
};

/*
class Solution {
public:
    int MOD = 1e9 + 7;
    int digitsum(string& s, int r1, int r2) {
        long long num = 0;
        long long sum = 0;
        for (int i = r1; i <= r2; i++) {
            if (s[i] != '0') {
                int d = (s[i] - '0');
                num = (num * 10 + d) % MOD;
                sum += d;
            }
        }

        return (num * sum) % MOD;
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int res = digitsum(s, queries[i][0], queries[i][1]);
            ans.push_back(res);
        }
        return ans;
    }
};
*/