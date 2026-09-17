class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (int i = 0; i < 32; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                cnt += (nums[j] >> i) & 1;
            }
            total += cnt * (n - cnt);
        }
        return total;
    }
};