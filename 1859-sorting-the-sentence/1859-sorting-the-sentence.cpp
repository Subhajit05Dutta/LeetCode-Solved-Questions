class Solution {
public:
    string sortSentence(string s) {
        vector<string> pos(10, "");
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int j = i;
            string temp = "";
            while (!isdigit(s[j])) {
                temp += s[j];
                j++;
            }
            pos[s[j] - '0'] = temp;
            i = j + 1;
        }
        string ans;
        for (int i = 0; i < 10; i++) {
            if (pos[i].size() > 0) {
                ans+=(pos[i]);
                ans += ' ';
            }
        }
        ans.pop_back();
        return ans;
    }
};