class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> st;
        for (int i = 0; i < brokenLetters.size(); i++) {
            st.insert(brokenLetters[i]);
        }
        int cnt = 0;
        for (int i = 0; i < text.size(); i++) {
            bool con = true;
            while (i < text.size() && text[i] != ' ') {
                if (st.find(text[i]) != st.end()) {
                    con = false;
                }
                i++;
            }
            if (con==true) {
                cnt += 1;
            }
        }
        return cnt;
    }
};