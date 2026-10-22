class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int n = nums.size();
        int odd = 0, even = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }

        vector<int> ans(n, 0);
        for (int i = even; i < n; i++) {
            ans[i] = 1;
        }
        return ans;
    }
};