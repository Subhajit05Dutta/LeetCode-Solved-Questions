class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string temp = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            string word = strs[i];
            string ans = "";
            for (int j = 0; j < word.size(); j++) {
                if (temp[j] == word[j]) {
                    ans += word[j];
                }
                else{
                    break;
                }
            }
            temp = ans;
        }
        return temp;
    }
};
