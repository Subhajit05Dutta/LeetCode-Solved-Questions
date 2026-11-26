class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        vector<int> ans(n);
        // Store all elements initially in suffix
        for (int i = n - 1; i >= 0; i--) {
            mp1[nums[i]]++;
        }
        for (int i = 0; i < n; i++) {

            mp1[nums[i]]--;
            if (mp1[nums[i]] == 0) {
                mp1.erase(nums[i]);
            }
            mp2[nums[i]]++;
            int pre = mp2.size();
            int suff = mp1.size();
            int diff = pre - suff;
            ans[i] = diff;
        }
        return ans;
    }
};