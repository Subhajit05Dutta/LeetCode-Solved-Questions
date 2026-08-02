class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0,prev_diff=INT_MAX;
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i-1]==nums[i]){
                continue;
            }

            int l=i+1;
            int r=n-1;
            while(l<r){
                long long sum=nums[i]+nums[l]+nums[r];
                if(sum==target){
                    return target;
                }
                int diff=abs(target-sum);
                if(diff<prev_diff){
                    ans=sum;
                    prev_diff=diff;
                }

                if(sum>target){
                    r--;
                }
                else if(sum<target){
                    l++;
                }
            }
        }
        return ans;
    }
};