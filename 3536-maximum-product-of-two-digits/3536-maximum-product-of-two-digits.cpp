class Solution {
public:
    int l = 0;
    int sl = 0;
    void find(int n) {
        while (n != 0) {
            int rem = n % 10;
            if (rem >= l) {
                sl = l;
                l = rem;
            } else if (rem > sl) {
                sl = rem;
            }
            n /= 10;
        }
    }
    int maxProduct(int n) {
        if (n < 10) {
            return n;
        }
        find(n);
        return l * sl;
    }
};