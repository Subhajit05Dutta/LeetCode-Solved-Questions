class Solution {
public:
    int firstUniqChar(string s) {
        int idx = -1;
        unordered_map<char, int> mpp;
        for (char i : s) {
            mpp[i]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (mpp[s[i]] == 1) {
                idx = i;
                break;
            }
        }
        return idx;
    }
};