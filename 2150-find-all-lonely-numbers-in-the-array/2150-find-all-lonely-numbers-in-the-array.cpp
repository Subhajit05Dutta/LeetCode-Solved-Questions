class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto& it : nums) {
            mp[it]++;
        }
        vector<int> res;
        for (auto& it : mp) {
            if (it.second == 1 && (mp.find(it.first - 1) == mp.end()) &&
                (mp.find(it.first + 1) == mp.end())) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};