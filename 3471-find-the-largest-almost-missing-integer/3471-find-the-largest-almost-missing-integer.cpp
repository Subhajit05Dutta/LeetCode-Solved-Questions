class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == n) {
            int large = nums[0];
            for (int i = 1; i < n; i++) {
                large = max(large, nums[i]);
            }
            return large;
        }
        unordered_map<int, int> mpp;
        for (int i : nums) {
            mpp[i]++;
        }

        if (k == 1) {
            int maxi = -1;
            for (int i = 0; i < n; i++) {
                if (mpp[nums[i]] == 1 && nums[i] > maxi) {
                    maxi = nums[i];
                }
            }
            return maxi;
        }
        int a = nums[0];
        int b = nums[n - 1];
        if (a == b) {
            return -1;
        }
        if (mpp[a] == 1 && mpp[b] == 1) {
            return max(a, b);
        }
        if (mpp[a] == 1 && mpp[b] > 1) {
            return a;
        }
        if (mpp[b] == 1 && mpp[a] > 1) {
            return b;
        }
        return -1;
    }
};