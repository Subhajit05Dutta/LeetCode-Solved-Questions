class Solution {
public:
    int countSegments(string s) {
        int n = s.size();
        int cnt = 0;
        int i = 0;
        string word = "";
        while (i < n) {
            if (s[i] != ' ') {
                word += s[i];
            } else {
                if (word.size() > 0)
                    cnt += 1;
                word = "";
            }
            i++;
        }
        if (i == n && word.size() > 0)
            cnt += 1;

        return cnt;
    }
};