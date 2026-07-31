class Solution {
public:
    vector<vector<int>> ans;
    void fun(vector<int>& candidates, int target, int idx, int n, int sum,
             vector<int>& temp) {
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        if (idx == n || sum > target) {
            return;
        }
        // Take
        temp.push_back(candidates[idx]);
        fun(candidates, target, idx + 1, n, sum+candidates[idx], temp);
        temp.pop_back();

        // Not Take (Skip  Duplicates)
        int i = idx;
        while (i + 1 < n && candidates[i] == candidates[i + 1]) {
            i++;
        }
        fun(candidates, target, i + 1, n, sum, temp);
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        fun(candidates, target, 0, n, 0, temp);
        return ans;
    }
};