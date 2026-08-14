class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        string strs = s + s;
        int n = s.size();

        for (int i = 0; i < strs.size(); i++) {
            if (strs[i] == goal[0]) {
                int j = 0;
                int k = i;
                while (j < goal.size() && k < strs.size()) {
                    if (goal[j] != strs[k]) {
                        break;
                    } else {
                        k++;
                        j++;
                    }
                }
                if (j == goal.size()) {
                    return true;
                }
            }
        }
        return false;
    }
};