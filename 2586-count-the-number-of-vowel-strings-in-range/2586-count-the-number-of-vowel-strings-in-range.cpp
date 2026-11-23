class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
        int cnt = 0;
        for (int i = left; i <= right; i++) {
            int sz = words[i].size();
            if (st.find(words[i][0]) != st.end() &&
                st.find(words[i][sz - 1]) != st.end()) {
                cnt++;
            }
        }
        return cnt;
    }
};