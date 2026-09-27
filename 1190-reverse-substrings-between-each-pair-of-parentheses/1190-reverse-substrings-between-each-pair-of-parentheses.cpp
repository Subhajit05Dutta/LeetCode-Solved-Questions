class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> link(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top();
                st.pop();
                link[i] = j;
                link[j] = i;
            }
        }
        string res;
        int i = 0, dir = 1;
        while (i >= 0 && i < n) {
            if (s[i] == '(' || s[i] == ')') {
                i = link[i];
                dir = -dir;
            } else {
                res += s[i];
            }
            i += dir;
        }
        return res;
    }
};