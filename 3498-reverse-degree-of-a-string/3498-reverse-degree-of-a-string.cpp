class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        int i = 0;
        while (i < s.size()) {
            // int cal = (i + 1) * (97 - ((int)(s[i])) + 26);
            int cal = (i + 1) * (26 - (s[i] - 'a'));
            sum = sum + cal;
            i++;
        }
        return sum;
    }
};