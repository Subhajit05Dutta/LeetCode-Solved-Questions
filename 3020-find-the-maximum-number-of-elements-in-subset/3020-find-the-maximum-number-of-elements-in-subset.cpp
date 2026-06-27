class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mp;
        for (auto& it : nums) {
            mp[it]++;
        }
        int ans = 0;
        // Handle number 1 separately because on squaring 1 it never changes.
        if (mp[1] % 2 == 0) {
            ans = mp[1] - 1;
        } else {
            ans = mp[1];
        }
        mp.erase(1);
        for (auto& [nums, _] : mp) {
            int len = 0;
            long long i = nums;
            for (; mp.contains(i) && mp[i] > 1; i *= i) {
                len += 2;
            }
            ans = max(ans, len + (mp.contains(i) ? 1 : -1));
        }
        return ans;
    }
};