class Solution {
public:
    bool isprime(int n) {
        if (n < 2) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    int count(int n) {
        int cnt = 0;
        while (n > 0) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                cnt++;
                n = (n - 1) / 2;
            }
        }
        bool ans = isprime(cnt);
        if (ans == false) {
            return 0;
        }
        return cnt;
    }
    int countPrimeSetBits(int left, int right) {
        int total = 0;
        for (int i = left; i <= right; i++) {
            int val = count(i);
            if (val > 0) {
                total += 1;
            }
        }
        return total;
    }
};