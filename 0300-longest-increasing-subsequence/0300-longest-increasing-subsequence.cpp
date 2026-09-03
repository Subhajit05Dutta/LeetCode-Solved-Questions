class Solution {
public:
    int fun(vector<int>& nums, int i, int n, int prev,vector<vector<int>>&dp) {
        if (i == n) {
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        if (prev == -1 || nums[i] > nums[prev]) {
            int c1 = 1 + fun(nums, i + 1, n, i,dp);
            int c2 = 0 + fun(nums, i + 1, n, prev,dp);
            return dp[i][prev+1]= max(c1, c2);
        }
        return dp[i][prev+1]=fun(nums, i + 1, n, prev,dp);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return fun(nums, 0, n, -1,dp);
    }
};

/*
    //Recursive Approach
    int fun(vector<int>&nums,int i,int n,int prev){
        if(i==n){
            return 0;
        }
        if(prev==-1 || nums[i]>nums[prev]){
            int c1=1+fun(nums,i+1,n,i);
            int c2=0+fun(nums,i+1,n,prev);
            return max(c1,c2);
        }
        return fun(nums,i+1,n,prev);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        return fun(nums,0,n,-1);
    }
*/