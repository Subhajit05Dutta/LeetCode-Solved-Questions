class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>res;
        if(n<4){
            return res;
        }
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<n-2;j++){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                int l=j+1,h=n-1;
                while(l<h){
                    long long sum=1LL*nums[i]+nums[j]+nums[l]+nums[h];
                    if(sum==target){
                        res.push_back({nums[i],nums[j],nums[l],nums[h]});
                        l++;
                        h--;
                        while(l<h && nums[l]==nums[l-1] ){
                            l++;
                        }
                        while(l<h && nums[h]==nums[h+1]){
                            h--;
                        }
                    }
                    else if(sum>target){
                        h--;
                    }
                    else if(sum<target){
                        l++;
                    }
                }
            }
        }
        return res;
    }
};