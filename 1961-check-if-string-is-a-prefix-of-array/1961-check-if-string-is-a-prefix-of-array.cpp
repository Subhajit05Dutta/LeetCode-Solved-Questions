class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string check = "";
        for (auto& it : words) {
            check += it;
            if (check == s)
                return true;
            if (check.length() >= s.length())
                return false;
        }
        return false;
    }
};