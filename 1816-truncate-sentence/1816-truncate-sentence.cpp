class Solution {
public:
    string truncateSentence(string s, int k) {
        int cnt = 0;
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            while (i < s.size() && s[i] != ' ') {
                ans += s[i];
                i++;
            }
            cnt++;
            if (cnt == k) {
                return ans;
            }
            if (i != s.size()) {
                ans += " ";
            }
        }
        return "";
    }
};