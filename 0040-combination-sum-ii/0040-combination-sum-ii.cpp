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
        // Take
        if (candidates[i] <= target) {
            list.push_back(candidates[i]);
            fun(candidates, target - candidates[i], i + 1, n, list, ans);
            list.pop_back();
        }
        int next = i + 1;
        while (next < n && candidates[i] == candidates[next]) {
            next++;
        }

        // Not Take
        fun(candidates, target, next, n, list, ans);

        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> list;
        vector<vector<int>> ans;
        int n = candidates.size();
        fun(candidates, target, 0, n, list, ans);
        return ans;
    }
};