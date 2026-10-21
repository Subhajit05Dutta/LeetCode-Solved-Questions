class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> st;
        for (int i : nums) {
            st.insert(i);
        }
        while (true) {
            if (st.find(original) != st.end()) {
                original *= 2;
            } else {
                break;
            }
        }
        return original;
    }
};