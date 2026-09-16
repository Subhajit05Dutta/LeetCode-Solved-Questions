class Solution {
public:
    void fun(vector<vector<int>>& ans, vector<int>& res, int i, int k, int n) {
        if (n == 0) {
            if (res.size() == k) {
                ans.push_back(res);
            }
            return;
        }
        if (i <= 9) {
            // Take
            res.push_back(i);
            fun(ans, res, i + 1, k, n - i);

            res.pop_back();

            // Not Take
            fun(ans, res, i + 1, k, n);
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> res;
        fun(ans, res, 1, k, n);
        return ans;
    }
};