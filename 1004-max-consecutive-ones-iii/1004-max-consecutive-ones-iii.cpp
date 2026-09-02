class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,h=0;
        int len=0;
        while(h<n){
            if(nums[h]==0){
                k--;
            }
            while(k<0){
                if(nums[l]==0){
                    k++;
                }
                l++;
                len=max(len,h-l+1);
            }
            len=max(len,h-l+1);
            h++;
        }
        return len;
    }
};