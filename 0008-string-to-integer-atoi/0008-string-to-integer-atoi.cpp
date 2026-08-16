class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int sign = 1;
        long long ans = 0;
        int i = 0;
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i == n) {
            return ans;
        }
        if ((s[i] == '+') || (s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        while ((i < n) && (isdigit(s[i]))) {
            int digit = s[i] - '0';
            ans = ans * 10 + digit;

            if (sign * ans > INT_MAX) {
                return INT_MAX;
            } else if (sign * ans < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }
        return (sign * ans);
    }
};