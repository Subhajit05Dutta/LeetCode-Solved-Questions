class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        set<int> st;
        for (auto& car : nums) {
            for (int i = car[0]; i <= car[1]; i++) {
                st.insert(i);
            }
        }
        return st.size();
    }
};