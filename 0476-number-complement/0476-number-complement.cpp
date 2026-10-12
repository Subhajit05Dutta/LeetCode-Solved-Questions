class Solution {
public:
    int findComplement(int num) {
        int dup = num;
        long long n = 1;
        while (dup != 0) {
            n *= 2;
            dup /= 2;
        }
        return n - num - 1;
    }
};