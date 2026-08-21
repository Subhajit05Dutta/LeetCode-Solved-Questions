class Solution {
public:
    void fun(vector<int>& candidates, int target, int i, int n,
             vector<int>& list, vector<vector<int>>& ans) {
        if (i == n) {
            if (target == 0) {
                ans.push_back(list);
            }
            return;
        }
        if (candidates[i] <= target) {
            // Take
            list.push_back(candidates[i]);
            fun(candidates, target - candidates[i], i, n, list, ans);
            list.pop_back();
        }

        // Not Take
        fun(candidates, target, i + 1, n, list, ans);

        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> list;
        vector<vector<int>> ans;
        int n = candidates.size();
        fun(candidates, target, 0, n, list, ans);
        return ans;
    }
};