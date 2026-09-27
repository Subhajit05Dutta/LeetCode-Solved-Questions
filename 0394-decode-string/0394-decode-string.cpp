class Solution {
public:
    string decodeString(string s) {
        stack<int> st1;
        stack<string> st2;
        string curr = "";
        int num = 0;
        for (char ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else if (ch == '[') {
                st1.push(num);
                st2.push(curr);
                curr = "";
                num = 0;
            } else if (ch == ']') {
                string temp = curr;
                curr = st2.top();
                st2.pop();
                int repeat = st1.top();
                st1.pop();
                while (repeat > 0) {
                    repeat--;
                    curr += temp;
                }
            } else {
                curr += ch;
            }
        }
        return curr;
    }
};