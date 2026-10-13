class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = 1LL * nums[i] * nums[i];
        }
        sort(temp.begin(), temp.end());
        int f = n / 2;
        if (n % 2 == 1) {
            f += 1;
        }
        int s = n - f;

        long long ans = 0;
        int i = 0;
        for (; i < s; i++) {
            ans -= temp[i];
        }
        for (; i < n; i++) {
            ans += temp[i];
        }

        return ans;
    }
};