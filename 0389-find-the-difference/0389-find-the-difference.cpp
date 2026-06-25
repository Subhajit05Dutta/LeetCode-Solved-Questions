class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        char ch;
        for (int i = 0; i < t.size(); i++) {
            if (mp[t[i]] == 0) {
                ch = t[i];
            } else {
                mp[t[i]]--;
            }
        }
        return ch;
    }
};