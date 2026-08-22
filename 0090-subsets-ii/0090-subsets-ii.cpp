class Solution {
public:
    void fun(vector<int>& nums, int i, vector<int>& list,
             vector<vector<int>>& ans) {

        ans.push_back(list);

        // Take
        for (int j = i; j < nums.size(); j++) {
            // Skip Duplicates
            if (j > i && nums[j] == nums[j - 1]) {
                continue;
            }
            list.push_back(nums[j]);
            fun(nums, j + 1, list, ans);
            list.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> list;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        fun(nums, 0, list, ans);
        return ans;
    }
};