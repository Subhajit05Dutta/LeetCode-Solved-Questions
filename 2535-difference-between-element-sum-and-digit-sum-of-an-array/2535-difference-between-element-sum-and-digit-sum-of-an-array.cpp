class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        int ele_sum=0;
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            while(n>0){
                int rem=n%10;
                n/=10;
                ele_sum+=rem;
            }
        }
        return abs(sum-ele_sum);
    }
};