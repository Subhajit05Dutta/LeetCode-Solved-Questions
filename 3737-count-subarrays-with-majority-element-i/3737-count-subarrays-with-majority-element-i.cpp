class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for (int l = 0; l < n; l++) {
            int cnt = 0;
            for (int r = l; r < n; r++) {
                if (nums[r] == target) {
                    cnt++;
                }
                int len = r - l + 1;
                if (cnt > len / 2) {
                    ans++;
                }
            }
        }
        return ans;
    }
};