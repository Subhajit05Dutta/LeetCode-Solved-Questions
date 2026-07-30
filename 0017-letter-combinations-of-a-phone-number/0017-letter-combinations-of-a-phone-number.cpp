class Solution {
public:
    vector<string> ans;
    void fun(string& s, int idx, int n, string& dairy, vector<string>& ans,
             unordered_map<char, string> mp) {
        // Base Case:
        // If we have processed all digits,
        // store the current combination.
        if (idx == n) {
            ans.push_back(dairy);
            return;
        }
        // Get all letters corresponding to the current digit
        string choice = mp[s[idx]];
        // Try every possible letter for the current digit
        for (int j = 0; j < choice.size(); j++) {
            // Choice
            dairy.push_back(choice[j]);
            // Explore the next digit
            fun(s, idx + 1, n, dairy, ans, mp);
            // Backtrack:
            // Remove the last chosen character
            // so that another choice can be tried.
            dairy.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        // Mapping of digits to corresponding letters
        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        int n = digits.size();
        string dairy = "";
        fun(digits, 0, n, dairy, ans, mp);
        return ans;
    }
};