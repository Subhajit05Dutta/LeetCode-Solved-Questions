class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = -1;
        int i = 0;
        while (i < s.size()) {
            if (isdigit(s[i])) {
                int val = 0;
                while (isdigit(s[i])) {
                    val = val * 10 + (s[i] - '0');
                    i++;
                }
                if (val <= prev) {
                    return false;
                } else {
                    prev = val;
                }
            }
            i++;
        }
        return true;
    }
};