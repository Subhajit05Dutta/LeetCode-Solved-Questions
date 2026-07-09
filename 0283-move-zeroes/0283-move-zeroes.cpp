class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                cnt += 1;
            } else {
                nums[j] = nums[i];
                j++;
            }
        }
        while (j < nums.size()) {
            nums[j] = 0;
            j++;
        }
        return;
    }
};