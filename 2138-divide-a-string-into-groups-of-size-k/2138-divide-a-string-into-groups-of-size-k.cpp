class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int i = 0;
        while (i < s.size()) {
            string st = "";
            while (st.size() < k && i < s.size()) {
                st += s[i];
                if (st.size() == k) {
                    ans.push_back(st);
                    break;
                }
                i++;
            }
            if (i == s.size()) {
                while (st.size() != k) {
                    st += fill;
                }
                ans.push_back(st);
            }
            i++;
        }
        return ans;
    }
};