class Solution {
public:
    bool checkValidString(string s) {
        if (s[0] == ')')
            return false;

        int mini = 0, maxi = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                mini += 1;
                maxi += 1;
            } else if (s[i] == ')') {
                mini -= 1;
                maxi -= 1;
            } else {
                mini -= 1;
                maxi += 1;
            }
            if (mini < 0) {
                mini = 0;
            }
            if (maxi < 0) {
                return false;
            }
        }

        return mini == 0;
    }
};

/*
//Alternative Approach

    bool fun(string& s, int idx, int cnt) {
        if (cnt < 0) {
            return false;
        } else if (idx == s.size()) {
            return cnt == 0;
        } else if (s[idx] == '(') {
            return fun(s, idx + 1, cnt + 1);
        } else if (s[idx] == ')') {
            return fun(s, idx + 1, cnt - 1);
        } else
            return (fun(s, idx + 1, cnt + 1) || fun(s, idx + 1, cnt - 1) ||
                    fun(s, idx + 1, cnt));
    }
    bool checkValidString(string s) {
        if (s[0] == ')')
            return false;

        return fun(s, 0, 0);
    }
*/