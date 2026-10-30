class Solution {
public:
    string makeFancyString(string s) {
        if (s.size() < 3) {
            return s;
        }
        string ans = "";
        ans = s.substr(0, 2);
        int i = 0, j = 1, k = 2;
        while (k < s.size()) {
            if (s[i] == s[j] && s[j] == s[k]) {
                i++;
                j++;
                k++;
            } else {
                ans += s[k];
                i++;
                j++;
                k++;
            }
        }
        return ans;
    }
};