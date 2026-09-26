class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mpp;
        for (char ch : s) {
            mpp[ch]++;
        }
        char ch;
        for (int i = 0; i < t.size(); i++) {
            if (mpp[t[i]] == 0) {
                ch = t[i];
            } else {
                mpp[t[i]]--;
            }
        }
        return ch;
    }
};