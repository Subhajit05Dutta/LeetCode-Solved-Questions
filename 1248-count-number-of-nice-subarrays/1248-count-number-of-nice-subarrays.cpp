class Solution {
public:
    int fun(vector<int>& nums, int k) {
        int odd = 0;
        int n = nums.size();
        int l = 0;
        int cnt = 0, ans = 0;
        for (int r = 0; r < n; r++) {
            if (nums[r] % 2 == 1) {
                cnt++;
            }
            while (cnt > k) {
                if (nums[l] % 2 == 1)
                    cnt--;
                l++;
            }
            ans += (r - l + 1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return fun(nums, k) - fun(nums, k - 1);
    }
};