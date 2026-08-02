class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int flag=INT_MIN;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            if(flag==INT_MIN){
                if(nums[i]<nums[i+1]){
                    flag=1;
                }
                else if(nums[i]>nums[i+1]){
                    flag=0;
                }
                else{
                    continue;
                }
            }
            else if (flag != INT_MIN) {
                if ((flag == 1 && nums[i + 1] < nums[i]) ||
                    (flag == 0 && nums[i + 1] > nums[i])) {
                    return false;
                }
            }
        }
        return  true;
    }
};