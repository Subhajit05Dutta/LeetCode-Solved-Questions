class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long st = 1;

        while (st <= n) {
            if (st == n) {
                return true;
            } else if (st < n) {
                st = st * 2;
            } else {
                break;
            }
        }
        if (st > n)
            return false;
        return true;
    }
};