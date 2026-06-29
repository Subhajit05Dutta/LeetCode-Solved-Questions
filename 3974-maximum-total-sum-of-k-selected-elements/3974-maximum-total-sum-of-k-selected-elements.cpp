class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end(), greater<int>());
        long long sum = 0;
        int i = 0;
        while (i < k) {
            sum += 1LL * nums[i] * max(mul - i, 1);
            i++;
        }
        return sum;
    }
};