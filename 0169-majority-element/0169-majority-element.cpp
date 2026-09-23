class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq=0;
        int ele=0;
        for(int i=0;i<nums.size();i++){
            if(freq==0){
                freq=1;
                ele=nums[i];
            }
            else{
                if(nums[i]==ele){
                    freq++;
                }
                else{
                    freq--;
                }
            }
        }
        return ele;
    }
};