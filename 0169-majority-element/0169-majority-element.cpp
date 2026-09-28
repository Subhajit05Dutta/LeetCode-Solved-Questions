class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = 0;
        int freq = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (freq == 0) {
                ele = nums[i];

            } 
            if (nums[i] == ele) {
                freq++;
            } else if (nums[i] != ele) {
                freq--;
            }
        }
        return ele;
    }
};