class Solution {
public:
    int reverse(int val) {
        int rem, ans = 0;
        while (val != 0) {
            rem = val % 10;
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) {
                return 0;
            }
            ans = ans * 10 + rem;
            val = val / 10;
        }
        return ans;
    }
};