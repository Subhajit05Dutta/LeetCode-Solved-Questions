class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st;
        for (auto& it : dictionary) {
            if (st.find(it) == st.end()) {
                st.insert(it);
            }
        }
        string ans = "";
        string word = "";
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ') {
                ans = ans + word + " ";
                word = "";
            } else {
                word += sentence[i];
                if (st.find(word) != st.end()) {
                    ans += word;
                    while (i < sentence.size() && sentence[i] != ' ') {
                        i++;
                    }
                    if (i < sentence.size()) {
                        ans += " ";
                    }
                    word = "";
                }
            }
        }
        if (!word.empty()) {
            ans += word;
        }
        return ans;
    }
};