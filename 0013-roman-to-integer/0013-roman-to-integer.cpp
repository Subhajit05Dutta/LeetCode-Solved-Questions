class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mpp = {{'I', 1},   {'V', 5},   {'X', 10},
                                        {'L', 50},  {'C', 100}, {'D', 500},
                                        {'M', 1000}};
        int n = s.size();
        int ans = 0;
        int i = 0;
        while (i < n) {
            if (i == n) {
                ans = ans + mpp[s[i]];
                i++;
            } else if (mpp[s[i]] < mpp[s[i + 1]]) {
                ans = ans + (mpp[s[i + 1]] - mpp[s[i]]);
                i = i + 2;
            } else {
                ans = ans + mpp[s[i]];
                i++;
            }
        }
        return ans;
    }
};