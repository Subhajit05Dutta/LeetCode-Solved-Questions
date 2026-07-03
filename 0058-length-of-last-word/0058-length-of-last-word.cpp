class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int end = n - 1;
        while (end >= 0 && s[end] == ' ') {
            // To avoid the spaces at last,decrease end pointer
            end--;
        }
        int cnt = 0;
        while (end >= 0 && isalpha(s[end])) {
            /*isalpha(char) is used to check for both alphabets and numeric
            characters but is alphanum(char) is used only to check alphabets*/
            cnt++;
            end--;
        }
        return cnt;
    }
};