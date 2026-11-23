class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<char> arr(26);
        char chr = 'a';
        int cnt = 0;
        string ans = "";
        for (char ch : key) {
            if (ch != ' ' && arr[ch - 'a'] == 0) {
                arr[ch - 'a'] = chr;
                chr = (char)(chr + 1);
                cnt++;
            }
            if (cnt == 26)
                break;
        }
        for (char ch : message) {
            if (ch == ' ') {
                ans += ' ';
            } else {
                ans += arr[ch - 'a'];
            }
        }
        return ans;
    }
};