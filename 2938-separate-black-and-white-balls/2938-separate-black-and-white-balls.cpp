class Solution {
public:
    long long minimumSteps(string s) {
        long long cnt = 0;
        int last = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                cnt += (i - last);
                last++;
            }
        }
        return cnt;
    }
};