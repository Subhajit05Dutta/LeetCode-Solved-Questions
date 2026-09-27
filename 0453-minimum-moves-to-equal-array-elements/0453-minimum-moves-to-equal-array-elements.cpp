class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m=INT_MAX;
        for(int n:nums){
           m= min(m,n);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=(nums[i]-m);
        }
        return ans;
    }
};