class Solution {
public:
    int division(vector<int>& nums, int mid) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % mid == 0) {
                sum += (nums[i] / mid);
            } else {
                sum += (nums[i] / mid + 1);
            }
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high;
        for (int i = 0; i < n; i++) {
            high = max(high, nums[i]);
        }
        int ans;
        while (low <= high) {
            int mid = (low + high) / 2;
            int sum = division(nums, mid);
            if (sum <= threshold) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};