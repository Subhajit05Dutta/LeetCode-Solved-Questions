class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mpp;
        unordered_set<int> st;
        for (int x : arr) {
            mpp[x]++;
        }
        for (auto& it : mpp) {
            if (st.find(it.second) == st.end()) {
                st.insert(it.second);
            } else {
                return false;
            }
        }
        return true;
    }
};