class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int maxi = -1;
        for (int i = 0; i < n; i++) {
            int need = -nums[i];
            if (st.find(need) == st.end()) {
                st.insert(nums[i]);
            } else {
                maxi = max(maxi, max(nums[i], need));
            }
        }
        return maxi;
    }
};