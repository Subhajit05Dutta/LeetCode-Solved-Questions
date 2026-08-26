class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n == 0) {
            return true;
        }
        if (s[0] == ')' || s[0] == '}' || s[0] == ']') {
            return false;
        }
        int i = 0;
        stack<char> st;
        while (i < n) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if ((!st.empty()) && ((s[i] == ')' && st.top() == '(') ||
                                      (s[i] == '}' && st.top() == '{') ||
                                      (s[i] == ']' && st.top() == '['))) {
                    st.pop();
                } else {
                    return false;
                }
            }
            i++;
        }
        if (i == n && st.empty()) {
            return true;
        }
        return false;
    }
};