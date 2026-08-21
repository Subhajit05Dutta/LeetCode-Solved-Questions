class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;
        int cnt = 0;
        while (ans > 0) {
            if (ans % 2 == 0) {
                ans /= 2;
            } else {
                cnt++;
                ans = (ans - 1) / 2;
                ;
            }
        }
        return cnt;
    }
};