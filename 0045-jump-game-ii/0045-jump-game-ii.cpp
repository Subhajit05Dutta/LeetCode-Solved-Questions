class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int max_idx = 0;
        int curr_end = 0;
        for (int i = 0; i < n-1; i++) {
            max_idx = max(max_idx, nums[i] + i);
            if (i == curr_end) {
                cnt++;
                curr_end = max_idx;
            }
        }
        return cnt;
    }
};