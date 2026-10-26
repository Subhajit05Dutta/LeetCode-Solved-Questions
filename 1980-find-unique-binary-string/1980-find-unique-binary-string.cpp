class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> st;
        for (auto& it : nums) {
            st.insert(it);
        }
        for (int i = 0; i < (1 << n); i++) {
            string s = "";
            for (int j = n - 1; j >= 0; j--) {
                if (i & (1 << j)) {
                    s += '1';
                } else {
                    s += '0';
                }
            }
            if (st.find(s) == st.end()) {
                return s;
            }
        }
        return "";
    }
};