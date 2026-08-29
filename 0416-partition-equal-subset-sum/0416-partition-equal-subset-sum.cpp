class Solution {
public:
    bool fun(vector<int>& nums,vector<vector<int>>&dp, int idx, int target) {
        if (target == 0) {
            return true;
        }
        if (idx == 0) {
            return (target == nums[0]);
        }
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        bool take = false;
        if (target >= nums[idx]) {
            take = fun(nums,dp, idx - 1, target - nums[idx]);
        }

        bool not_take = fun(nums, dp,idx - 1, target);

        return dp[idx][target]=(take || not_take);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totsum = 0;
        for (int i = 0; i < n; i++) {
            totsum += nums[i];
        }
        if (totsum % 2 == 1) {
            // Total sum is odd so it can't be divided into 2 equal parts.
            return false;
        }
        vector<vector<int>>dp(n,vector<int>(totsum/2+1,-1));
        return fun(nums,dp, n - 1, totsum / 2);
    }
};


/*
//Recursive Approach
    bool fun(vector<int>& nums, int idx, int target) {
        if (target == 0) {
            return true;
        }
        if (idx == 0) {
            return (target == nums[0]);
        }

        bool take = false;
        if (target >= nums[idx]) {
            take = fun(nums, idx - 1, target - nums[idx]);
        }

        bool not_take = fun(nums, idx - 1, target);

        return (take || not_take);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totsum = 0;
        for (int i = 0; i < n; i++) {
            totsum += nums[i];
        }
        if (totsum % 2 == 1) {
            // Total sum is odd so it can't be divided into 2 equal parts.
            return false;
        }
        return fun(nums, n - 1, totsum / 2);
    }
*/