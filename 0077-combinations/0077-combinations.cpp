class Solution {
public:
    void fun(int i, int n, int k, vector<int>& list, vector<vector<int>>& ans) {
        if (i > n) {
            if (list.size() == k) {
                ans.push_back(list);
            }
            return;
        }

        // Take
        list.push_back(i);
        fun(i + 1, n, k, list, ans);
        list.pop_back();

        // Not Take
        fun(i + 1, n, k, list, ans);

        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> list;
        vector<vector<int>> ans;
        fun(1, n, k, list, ans);
        return ans;
    }
};