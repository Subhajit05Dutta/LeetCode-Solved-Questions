class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int k = n - 1;
            while (nums[k] <= nums[i]) {
                k--;
            }
            swap(nums[i], nums[k]);
        }
        reverse(nums.begin() + i + 1, nums.end());
        return;
    }
};