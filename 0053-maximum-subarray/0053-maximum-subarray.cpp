class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int r=0;
        int maxsum=INT_MIN;
        int sum=0;
        while(r<n){
            sum+=nums[r];
            maxsum=max(maxsum,sum);
            if(sum<0){
                sum=0;
            }
            r++;
        }
        return maxsum;
    }
};