class Solution {
public:
    bool judgeSquareSum(int c) {
        int n = sqrt(c);
        vector<int> arr(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            arr[i] = i;
        }
        long long low = 0, high = n;
        while (low <= high) {

            if (low * low + high * high == c) {
                return true;
            } else if (low * low + high * high > c) {
                high--;
            } else {
                low++;
            }
        }
        return false;
    }
};