class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=0,i=0;
        while(i<n){
            int j=i;
            while(j<n && nums[j]==nums[i]){
                j++;
            }
            int freq=j-i;
            int right=n-j;

            cnt+=(freq*left*right);
            left+=freq;
            i=j;

        }
        return cnt;
    }
};