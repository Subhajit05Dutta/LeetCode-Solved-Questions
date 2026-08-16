class Solution {
public:
    static bool cmp(pair<char, int>& p1, pair<char, int>& p2) {
        if (p1.second > p2.second)
            return true;
        return false;
    }
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        vector<pair<char, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), cmp);

        string ans = "";
        for (auto& it : vec) {
            for (int i = 0; i < it.second; i++) {
                ans += it.first;
            }
        }
        return ans;
    }
};