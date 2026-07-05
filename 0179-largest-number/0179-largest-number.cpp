class Solution {
public:
    static bool cmp(string& a, string& b) { return a + b > b + a; }
    string largestNumber(vector<int>& nums) {
        vector<string> res;
        for (int& x : nums) {
            res.push_back(to_string(x));
        }
        sort(res.begin(), res.end(), cmp);
        if (res[0] == "0")
            return "0";
        string ans = "";
        for (string& s : res) {
            ans += s;
        }
        return ans;
    }
};