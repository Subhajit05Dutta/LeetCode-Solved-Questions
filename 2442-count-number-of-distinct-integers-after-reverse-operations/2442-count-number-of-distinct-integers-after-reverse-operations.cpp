class Solution {
public:
    int reverse(int n) {
        int ans = 0;
        while (n > 0) {
            int rem = (n % 10);
            ans = ans * 10 + rem;
            n /= 10;
        }
        return ans;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
            st.insert(reverse(nums[i]));
        }
        return st.size();
    }
};