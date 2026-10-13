class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int idx = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (maxi < nums[i]) {
                idx = i;
                maxi = nums[i];
            }
        }
        int sum = 0;
        while (k > 0) {
            sum += maxi;
            nums[idx] = nums[idx] + 1;
            maxi += 1;
            k--;
        }
        return sum;
    }
};