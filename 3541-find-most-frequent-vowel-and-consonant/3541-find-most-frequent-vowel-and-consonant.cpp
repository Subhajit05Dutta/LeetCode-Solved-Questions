class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> cons;
        unordered_map<char, int> vow;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                vow[s[i]]++;
            } else {
                cons[s[i]]++;
            }
        }
        int mxv = 0, mxc = 0;
        for (auto it : vow) {
            if (it.second > mxv) {
                mxv = it.second;
            }
        }
        for (auto it : cons) {
            if (it.second > mxc) {
                mxc = it.second;
            }
        }
        return mxv + mxc;
    }
};