class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0, high = 1;
        int sol=1;
        unordered_map<int, int> mpp;
        mpp[nums[0]]++;
        while (high < n) {
            mpp[nums[high]]++;
            while (mpp[nums[high]] > k) {
                mpp[nums[low]]--;
                low++;
            }
            sol = max(sol, high - low + 1);
            high++;
        }
        return sol;
    }
};