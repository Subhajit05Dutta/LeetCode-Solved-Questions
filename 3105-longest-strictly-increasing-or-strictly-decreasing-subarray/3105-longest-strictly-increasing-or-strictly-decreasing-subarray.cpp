class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inclen = 1, declen = 1, maxi = 1;
        int l = 0, r = 0;
        for (int pos = 0; pos < nums.size()-1; pos++) {
            if (nums[pos + 1] > nums[pos]) {
                inclen++;
                declen = 1;
            } else if (nums[pos + 1] < nums[pos]) {
                declen++;
                inclen = 1;
            } else {
                inclen = 1;
                declen = 1;
            }
            maxi = max(maxi, max(inclen, declen));
        }
        return maxi;
    }
};