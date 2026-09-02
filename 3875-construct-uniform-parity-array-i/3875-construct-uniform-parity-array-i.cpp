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
        //It's always doable. return 1
        if(even==n || odd==n){
            return true;
        }
        /*
        If the elements of nums1 are all even or all odd, just set nums2=nums1
        Otherwise there must exist some odd x in nums1, use z=y-x for all even y in nums1, & z=y for all odd y in nums1 to make all z odd.
        */
        return true;
    }
};