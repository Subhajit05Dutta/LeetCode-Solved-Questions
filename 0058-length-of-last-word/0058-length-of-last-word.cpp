class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n - 1;
        string ans = "";
        while (s[i] == ' ') {
            i--;
        }
        while (i >= 0 && s[i] != ' ') {
            ans = ans + s[i];
            i--;
        }
        return ans.size();
    }
};