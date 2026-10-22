class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        double mini = INT_MAX;
        while (l < r) {
            double val = (double)((nums[l] + nums[r]) / 2.0);
            mini = min(mini, val);
            l++;
            r--;
        }
        return mini;
    }
};