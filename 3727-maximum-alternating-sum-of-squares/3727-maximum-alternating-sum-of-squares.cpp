class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        //Take the squares of all in a different array.
        vector<long long> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = 1LL * nums[i] * nums[i];
        }
        //Sort them.
        sort(temp.begin(), temp.end());

        //Divide them into two parts, elements which are going to add and elements which are going to substract.
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