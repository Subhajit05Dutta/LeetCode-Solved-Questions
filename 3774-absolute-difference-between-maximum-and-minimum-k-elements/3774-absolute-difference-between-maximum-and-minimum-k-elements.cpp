class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0, diff = 0;
        for (int i = 0; i < k; i++) {
            diff += nums[i];
            sum += nums[n - 1 - i];
        }
        return abs(sum - diff);
    }
};