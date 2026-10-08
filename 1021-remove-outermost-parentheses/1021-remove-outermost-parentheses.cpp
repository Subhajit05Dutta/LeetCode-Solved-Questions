class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string ans = "";
        for (int i = 0; i < s.size(); i++) {

            // For ')', decrease cnt FIRST because this ')' is
            // closing a parenthesis. We need to know the depth
            // AFTER removing this closing bracket.
            if (s[i] == ')') {
                cnt--;
            }

            // If cnt != 0, this parenthesis is NOT an outermost
            // parenthesis, so we add it to the answer.
            // If cnt == 0, this ')' is the outermost closing
            // parenthesis, so we skip it.

            if (cnt != 0) {
                ans.push_back(s[i]);
            }
            // For '(', increase cnt AFTER checking.
            // This is because the current '(' is the outermost
            // opening parenthesis when cnt was 0, so we don't want to add it to
            // the answer.
            // After processing it, we increase cnt to represent the
            // new nesting depth.
            if (s[i] == '(') {
                cnt++;
            }
            
        }
        return ans;
    }
};