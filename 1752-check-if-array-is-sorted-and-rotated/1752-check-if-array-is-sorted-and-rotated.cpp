class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n - 1 && nums[i] <= nums[i + 1]) {
            i++;
        }
        // Already sorted
        if (i == n - 1) {
            return true;
        }
        i = i + 1;
        while (i < n - 1 && nums[i] <= nums[i + 1]) {
            i++;
        }

        if (i == n - 1 && nums[i] <= nums[0])
            return true;
        return false;
    }
};
