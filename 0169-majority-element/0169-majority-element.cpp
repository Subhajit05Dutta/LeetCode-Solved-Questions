class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq=0;
        int ele;
        for(int i=0;i<nums.size();i++){
            if(freq==0){
             ele=nums[i];
            }
            if(nums[i]==ele){
                freq++;
            }
            else{
                freq--;
            }
        }
        return ele;
    }
};