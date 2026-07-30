class Solution {
public:
    vector<string> ans;
    void fun(string& s, int idx, int n, string& dairy, vector<string>& ans,
             unordered_map<char, string> mp) {
        if (idx == n) {
            ans.push_back(dairy);
            return;
        }
        string choice = mp[s[idx]];
        for (int j = 0; j < choice.size(); j++) {
            dairy.push_back(choice[j]);
            fun(s, idx + 1, n, dairy, ans, mp);
            dairy.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        int n = digits.size();
        string dairy = "";
        fun(digits, 0, n, dairy, ans, mp);
        return ans;
    }
};