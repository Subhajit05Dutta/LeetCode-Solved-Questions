class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string word = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            string temp = "";
            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == word[j]) {
                    temp += word[j];
                } else {
                    break;
                }
            }
            word = temp;
        }
        return word;
    }
};