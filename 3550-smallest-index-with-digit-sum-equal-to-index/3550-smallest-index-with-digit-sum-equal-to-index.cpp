class Solution {
public:
    int sum_of_digits(int n){
        int sum=0;
        while(n>0){
            int digit=n%10;
            sum+=digit;
            n/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        int idx=-1;
        for(int i=0;i<n;i++){
            int sum=sum_of_digits(nums[i]);
            if(sum==i){
                idx=i;
                break;
            }
        }
        return idx;
    }
};