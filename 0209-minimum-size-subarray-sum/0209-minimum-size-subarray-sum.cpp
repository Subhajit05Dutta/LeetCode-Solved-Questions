class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int minlen=INT_MAX;
        int l=0,h=0;
        int sum=0;
        while(h<n){
            sum+=nums[h];
            while(sum>=target){
                int len=h-l+1;
                minlen=min(len,minlen);
                sum-=nums[l];
                l++;
            }
            h++;
        }
        if(minlen==INT_MAX){
            return 0;
        }
        return minlen;
    }
};