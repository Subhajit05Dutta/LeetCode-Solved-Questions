class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        if (s[0] == ')' || s[0] == '}' || s[0] == ']') {
            return false;
        }
        int i = 0;
        while (i < n) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (st.empty()) {
                    return false;
                } else if (s[i] == ')' && st.top() == '(') {
                    st.pop();
                } else if (s[i] == '}' && st.top() == '{') {
                    st.pop();
                } else if (s[i] == ']' && st.top() == '[') {
                    st.pop();
                } else {
                    return false;
                }
            }
            i++;
        }
        return st.empty();
    }
};