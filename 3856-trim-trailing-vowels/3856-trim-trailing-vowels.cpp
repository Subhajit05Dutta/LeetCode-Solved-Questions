class Solution {
public:
    string trimTrailingVowels(string s) {
        int i = s.size() - 1;
        while (i >= 0) {
            if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                 s[i] == 'u')) {
                i--;
            } else {
                break;
            }
        }
        if (i < 0) {
            return "";
        }
        return s.substr(0, i + 1);
    }
};