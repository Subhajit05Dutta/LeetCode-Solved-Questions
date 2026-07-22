class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int small=INT_MAX;
        int large=INT_MIN;
        int n=nums.size();
        vector<int>ans;

        unordered_set<int>st;
        for(int i=0;i<n;i++){
            small=min(small,nums[i]);
            large=max(large,nums[i]);
            if(st.find(nums[i])==st.end()){
                st.insert(nums[i]);
            }
        }

        for(int i=small;i<=large;i++){
            if(st.find(i)==st.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};