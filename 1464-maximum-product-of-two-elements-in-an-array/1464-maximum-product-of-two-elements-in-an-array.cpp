class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int fmax = nums[0];
        int smax = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > fmax) {
                smax = fmax;
                fmax = nums[i];
            } else if (nums[i] > smax) {
                smax = nums[i];
            }
        }
        return ((fmax - 1) * (smax - 1));
    }
};