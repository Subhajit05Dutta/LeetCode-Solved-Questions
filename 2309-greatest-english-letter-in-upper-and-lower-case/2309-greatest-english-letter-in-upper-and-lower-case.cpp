class Solution {
public:
    string greatestLetter(string s) {
        vector<int> temp(26, 0);
        unordered_set<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (islower(s[i])) {
                if (st.find(toupper(s[i])) != st.end()){
                    temp[toupper(s[i]) - 'A']++;
                }
            }
            if (isupper(s[i])) {
                if (st.find(tolower(s[i])) != st.end()) {
                    temp[toupper(s[i]) - 'A']++;
                }
            }
            st.insert(s[i]);
        }
        for (int i = 25; i >= 0; i--) {
            if (temp[i] != 0) {
                return string(1,'A' + i);
            }
        }
        return "";
    }
};