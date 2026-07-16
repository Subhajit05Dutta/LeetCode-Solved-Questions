class Solution {
public:
    bool checkString(string s) {
        int flag = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'b') {
                if (flag == 0)
                    flag = 1;
            } else if (flag == 1 && s[i] == 'a') {
                return false;
            }
        }
        return true;
    }
};