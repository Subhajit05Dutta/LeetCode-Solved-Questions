class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        int cnt = 0;

        unordered_map<int, bool> mpp;
        for (int i : nums) {
            mpp[i] = true;
        }
        for (int i = 0; i < n; i++) {
            if ((mpp[nums[i] - diff]) && (mpp[nums[i] + diff])) {
                cnt++;
            }
        }
        return cnt;
    }
};