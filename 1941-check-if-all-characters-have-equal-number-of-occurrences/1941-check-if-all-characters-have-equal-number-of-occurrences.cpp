class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> mpp;
        for (auto& it : s) {
            mpp[it]++;
        }
        int cnt = mpp[s[0]];
        for (auto& it : mpp) {
            if (it.second != cnt) {
                return false;
            }
        }
        return true;
    }
};