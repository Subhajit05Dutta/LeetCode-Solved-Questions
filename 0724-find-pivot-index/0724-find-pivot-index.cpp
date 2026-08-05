class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int leftsum = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        // Specifically checking for nums[0]
        int rightsum = sum - leftsum - nums[0];
        if (leftsum == rightsum) {
            return 0;
        }
        for (int i = 1; i < n; i++) {
            leftsum += nums[i - 1];
            rightsum = sum - leftsum - nums[i];
            if (leftsum == rightsum) {
                return i;
            }
        }
        return -1;
    }
};