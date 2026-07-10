class Solution {
public:
    const int MOD = 1e9 + 7;
    long long fact(int n) {
        long long ans = 1;
        while (n > 1) {
            ans = (ans * n) % MOD;
            n--;
        }
        return ans;
    }
    int numPrimeArrangements(int n) {
        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            int isprime = 1;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isprime = 0;
                    break;
                }
            }
            if (isprime) {
                cnt++;
            }
        }
        int normal = n - cnt;
        int total = (fact(cnt) * fact(normal)) % (MOD);
        return total;
    }
};