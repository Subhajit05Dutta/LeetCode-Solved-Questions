class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            int idx = 0;
            int mini = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (nums[i] < mini) {
                    mini = nums[i];
                    idx = i;
                }
            }
            nums[idx] = multiplier * nums[idx];
        }
        return nums;
    }
};