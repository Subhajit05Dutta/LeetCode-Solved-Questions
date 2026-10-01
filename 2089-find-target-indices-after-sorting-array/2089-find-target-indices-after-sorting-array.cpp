class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int l = 0, h = n - 1;
        int first = -1, last = -1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] == target) {
                first = m;
                h = m - 1;
            } else if (nums[m] > target) {
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        l = 0, h = n - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (nums[m] == target) {
                last = m;
                l = m + 1;
            } else if (nums[m] > target) {
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        if (first != -1) {
            for (int i = first; i <= last; i++) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};