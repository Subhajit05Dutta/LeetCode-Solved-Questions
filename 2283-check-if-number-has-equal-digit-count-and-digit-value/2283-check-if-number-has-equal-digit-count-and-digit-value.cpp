class Solution {
public:
    bool digitCount(string num) {
        int n = num.size();
        vector<int> res(10, 0);
        for (int i = 0; i < n; i++) {
            res[num[i] - '0']++;
        }
        for (int i = 0; i < n; i++) {
            if (num[i] - '0' != res[i]) {
                return false;
            }
        }
        return true;
    }
};