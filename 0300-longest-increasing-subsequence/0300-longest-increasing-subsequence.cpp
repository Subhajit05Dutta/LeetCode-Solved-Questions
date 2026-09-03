class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    res[i] = max(res[i], res[j] + 1);
                }
            }
        }
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, res[i]);
        }
        return maxi;
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


    //Memoization (Top-Down Approach)
    int fun(vector<int>& nums, int i, int n, int prev,
            vector<vector<int>>& dp) {
        if (i == n) {
            return 0;
        }
        if (dp[i][prev + 1] != -1) {
            return dp[i][prev + 1];
        }
        if (prev == -1 || nums[i] > nums[prev]) {
            int c1 = 1 + fun(nums, i + 1, n, i, dp);    // take nums[i]
            int c2 = 0 + fun(nums, i + 1, n, prev, dp); // skip nums[i]
            return dp[i][prev + 1] = max(c1, c2);
        }
        return dp[i][prev + 1] =
                   fun(nums, i + 1, n, prev,
                       dp); // we have to skip nums[i], there is no choice.
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        retu
*/