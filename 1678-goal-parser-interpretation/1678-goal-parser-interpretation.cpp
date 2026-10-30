class Solution {
public:
    string interpret(string command) {
        string ans = "";
        int i = 0;
        while (i < command.size()) {
            if (command[i] == 'G') {
                ans += "G";
                i += 1;
            } else if (command[i] == '(') {
                if (command[i + 1] == ')') {
                    ans += "o";
                    i += 2;
                } else if (command[i + 1] == 'a') {
                    ans += "al";
                    i += 4;
                }
            }
        }
        return ans;
    }
};