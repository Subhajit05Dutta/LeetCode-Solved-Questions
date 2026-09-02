class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int odd=0,even=0;
        for(int i:nums1){
            if(i%2==0){
                even++;
            }
            else{
                odd++;
            }
        }
        if(even==n || odd==n){
            return true;
        }
        vector<int>nums2(n);
        int i=0;
        while(nums1[i]%2==0){
            i++;
        }
        for(int j=0;j<n;j++){
            if(nums1[j]%2==1){
                continue;
            }
            else{
                nums1[j]=nums1[j]-nums1[i];
            }
        }
        return true;
    }
};