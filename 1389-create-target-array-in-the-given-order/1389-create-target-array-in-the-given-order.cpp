class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> target(n, -1);
        for (int i = 0; i < n; i++) {
            int idx = index[i];
            if (target[idx] == -1) {
                target[idx] = nums[i];
            } else {
                int j = n - 1;
                while (j > idx) {
                    target[j] = target[j - 1];
                    j--;
                }
                target[j] = nums[i];
            }
        }
        return target;
    }
};