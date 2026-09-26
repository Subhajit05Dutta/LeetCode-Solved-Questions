class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int all=n*(n+1)/2;
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        int ans=all-sum;
        return ans;
    }
};