class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>ref=(nums);
        sort(nums.begin(),nums.end());
        int l=-1,r=-1;
        for(int i=0;i<nums.size();i++){
            if((nums[i]!=ref[i]) && l==-1){
                l=i;
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if((nums[i]!=ref[i]) && r==-1){
                r=i;
                break;
            }
        }
        if(l==-1 && r==-1)
        return 0;
        return (r-l+1);
    }
};