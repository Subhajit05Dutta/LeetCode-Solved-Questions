class Solution {
public:
    bool checkString(string s) {
        bool seen = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' && seen == true) {
                return false;
            } else if (s[i] == 'a' && seen == false) {
                continue;
            } else if (s[i] == 'b') {
                seen = true;
            }
        }
        return true;
    }
};