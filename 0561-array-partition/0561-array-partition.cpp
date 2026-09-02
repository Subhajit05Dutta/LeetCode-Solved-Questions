class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        if (n < 2)
            return ans;
        int i = 0, j = 1;
        for (int k = 0; k < n; k += 2) {
            ans += nums[k];
        }
        return ans;
    }
};