class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ans1 = "";
        string ans2 = "";
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '#') {
                st.push(s[i] - 'a');
            } else {
                if (!st.empty())
                    st.pop();
            }
        }
        while (!st.empty()) {
            ans1 += st.top();
            st.pop();
        }
        for (int i = 0; i < t.size(); i++) {
            if (t[i] != '#') {
                st.push(t[i] - 'a');
            } else {
                if (!st.empty())
                    st.pop();
            }
        }
        while (!st.empty()) {
            ans2 += st.top();
            st.pop();
        }
        if (ans1 == ans2)
            return true;
        return false;
    }
};