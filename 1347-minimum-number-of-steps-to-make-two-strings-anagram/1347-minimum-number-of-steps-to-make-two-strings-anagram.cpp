class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> ele(26, 0);
        for (auto& it : s) {
            ele[it - 'a']++;
        }
        for (auto& it : t) {
            ele[it - 'a']--;
        }
        int cnt = 0;
        for (auto& it : ele) {
            if (it > 0)
                cnt += it;
        }
        return cnt;
    }
};