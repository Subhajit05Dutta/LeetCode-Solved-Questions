class Solution {
public:
    string replaceDigits(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                char ch = s[i - 1] + (s[i] - '0');
                ans += ch;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};