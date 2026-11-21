class Solution {
public:
    int countAsterisks(string s) {
        int cnt = 0;
        bool inside = false;
        for (char ch : s) {
            if (inside == false && ch == '*') {
                cnt++;
            } else if (ch == '|') {
                inside = !inside;
            }
        }
        return cnt;
    }
};