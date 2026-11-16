class Solution {
public:
    string digitSum(string s, int k) {
        if (s.size() <= k) {
            return s;
        }
        while (s.size() > k) {
            string temp = "";
            int i = 0;
            while (i < s.size()) {
                int sum = 0;
                for (int j = i; j < i + k && j < s.size(); j++) {
                    int digit = s[j] - '0';
                    sum += digit;
                }
                temp += (to_string(sum));
                i += k;
            }
            s = temp;
        }
        return s;
    }
};