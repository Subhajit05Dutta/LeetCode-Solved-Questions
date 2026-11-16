class Solution {
public:
    string freqAlphabets(string s) {
        int n = s.size();
        string res = "";
        int i = 0;
        while (i < n) {
            if ((i + 2) < n && s[i + 2] == '#') {
                int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                res += char(num + 'a' - 1);
                i += 3;
            } else {
                res += char(s[i] - '0' - 1 + 'a');
                i += 1;
            }
        }
        return res;
    }
};