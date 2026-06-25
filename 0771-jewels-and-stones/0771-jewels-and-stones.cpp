class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> st;
        for (auto& it : jewels) {
            st.insert(it);
        }
        int cnt = 0;
        for (int i = 0; i < stones.size(); i++) {
            if (st.find(stones[i]) != st.end()) {
                cnt++;
            }
        }
        return cnt;
    }
};