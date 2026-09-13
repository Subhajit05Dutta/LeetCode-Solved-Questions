class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char, int> st;
        int n = s.size();
        int cnt = 0;
        if (n < 3) {
            return cnt;
        }
        int i = 0;
        int j = 0;
        while (i < n) {
            st[s[i]]++;

            if (i - j + 1 > 3) {
                st[s[j]]--;
                if (st[s[j]] == 0) {
                    st.erase(s[j]);
                }
                j++;
            }
            if (st.size() == 3 && (i - j + 1) == 3) {
                cnt += 1;
            }
            i++;
        }
        return cnt;
    }
};