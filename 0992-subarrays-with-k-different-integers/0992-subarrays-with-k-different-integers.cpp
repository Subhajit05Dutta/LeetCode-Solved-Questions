class Solution {
public:
    int atmostk(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int l = 0, r = 0;
        int n = nums.size();
        int cnt = 0;
        while (r < n) {
            mp[nums[r]]++;

            while (mp.size() > k) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }
                l++;
            }
            // All subarrays [l..r], [l+1..r], ... [r..r]
            // have at most k distinct elements.
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (atmostk(nums, k) - atmostk(nums, k - 1));
    }
};