class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            int digit = 0;
            while (n > 0) {
                digit++;
                n /= 10;
            }
            if (digit % 2 == 0) {
                cnt++;
            }
        }
        return cnt;
    }
};