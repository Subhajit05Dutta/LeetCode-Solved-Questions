class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        // Sort array in descending order.
        sort(nums.rbegin(), nums.rend());
        int cnt = 0;
        int prev_unique = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] == prev_unique) {
                continue;
            }
            if (nums[i] < prev_unique) {
                cnt += i;
            }
            prev_unique = nums[i];
        }
        return cnt;
    }
};