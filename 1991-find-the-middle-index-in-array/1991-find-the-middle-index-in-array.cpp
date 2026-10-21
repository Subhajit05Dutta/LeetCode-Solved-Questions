class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> sumleft(n);
        vector<int> sumright(n);
        int sum_l = 0, sum_r = 0;
        for (int i = 0; i < n; i++) {
            sumleft[i] = sum_l;
            sum_l += nums[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            sumright[i] = sum_r;
            sum_r += nums[i];
        }
        for (int i = 0; i < n; i++) {
            if (sumleft[i] == sumright[i]) {
                return i;
            }
        }
        return -1;
    }
};