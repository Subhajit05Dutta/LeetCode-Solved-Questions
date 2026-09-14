class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n=nums.size();
        int first=-1,last=-1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(abs(nums[i]-nums[j])>=valueDifference){
                    if(abs(i-j)>=indexDifference){
                        first=i;
                        last=j;
                        return {first,last};
                    }
                }
            }
        }
        return {first,last};
    }
};