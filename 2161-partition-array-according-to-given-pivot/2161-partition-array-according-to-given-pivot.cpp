class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int maxcnt=0,mincnt=0,same=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>pivot){
                maxcnt++;
            }
            else if(nums[i]<pivot){
                mincnt++;
            }
            else{
                same++;
            }
        }
        vector<int>ans(nums.size());
        int i=0,j=mincnt,k=mincnt+same;
        for(int p=0;p<nums.size();p++){
            if(nums[p]>pivot){
                ans[k++]=nums[p];
            }
            else if(nums[p]<pivot){
                ans[i++]=nums[p];
            }
            else{
                ans[j++]=nums[p];
            }
        }
        return ans;
    }
};