class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;
        int large = k;
        for (int i = 0; i < n; i++) {
            if (nums[i] % k == 0) {
                st.insert(nums[i]);
                large = max(large, nums[i]);
            }
        }
        int smallest = -1;
        for (int i = k; i <= large; i = i + k) {
            if (st.find(i) == st.end()) {
                smallest = i;
                break;
            }
        }
        if (smallest == -1) {
            return large + k;
        }
        return smallest;
    }
};