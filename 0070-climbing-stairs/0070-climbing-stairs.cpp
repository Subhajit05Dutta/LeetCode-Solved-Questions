class Solution {
public:
    unordered_map<int,int>dp;
    int fun(int i,int n){
        if(i==n){
            return 1;
        }
        if(i>n){
            return 0;
        }

        if(dp.find(i)!=dp.end()){
            return dp[i];
        }
        int a1=fun(i+1,n);
        int a2=fun(i+2,n);
        dp[i]=a1+a2;
        return dp[i];
    }
    int climbStairs(int n) {
        int total= fun(0,n);
         return total;
    }
};

/*
// int total(int n, unordered_map<int, int>& dp) {
    //     if (n == 0 || n == 1) {
    //         return 1;
    //     }
    //     if (dp.find(n) == dp.end()) {
    //         dp[n] = total(n - 1, dp) + total(n - 2, dp);
    //     }
    //     return dp[n];
    // }
    // int climbStairs(int n) {
    //     unordered_map<int, int> dp;
    //     return total(n, dp);
    // }
*/