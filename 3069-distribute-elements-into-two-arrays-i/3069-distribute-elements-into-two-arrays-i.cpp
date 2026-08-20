class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int lastA=nums[0];
        int lastB=nums[1];
        int n=nums.size();
        int i=2;
        while(i<n){
            if(lastA>lastB){
                arr1.push_back(nums[i]);
                lastA=nums[i];
                i++;
            }
            else{
                arr2.push_back(nums[i]);
                lastB=nums[i];
                i++;
            }
        }
        int j=0;
        while(j<arr2.size()){
            arr1.push_back(arr2[j]);
            j++;
        }
        return arr1;
    }
};