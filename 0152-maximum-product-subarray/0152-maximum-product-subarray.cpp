class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int prefix_prod=1,suffix_prod=1;
        int res=INT_MIN;
        
        for(int i=0;i<n;i++){
            if(prefix_prod==0){
                prefix_prod=1;
            }
            if(suffix_prod==0){
                suffix_prod=1;
            }

            prefix_prod*=nums[i];
            suffix_prod*=nums[n-1-i];

            res=max(res,max(prefix_prod,suffix_prod));
        }
        return res;
    }
};