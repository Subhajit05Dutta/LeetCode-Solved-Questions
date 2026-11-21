class Solution {
public:
    int getLucky(string s, int k) {
        string temp = "";
        for (int i = 0; i < s.size(); i++) {
            temp += to_string(s[i] - 'a' + 1);
        }
        for (int i = 0; i < k; i++) {
            int j = 0;
            int total = 0;
            while (j < temp.size()) {
                total += (temp[j] - '0');
                j++;
            }
            temp = to_string(total);
        }
        return stoi(temp);
    }
};