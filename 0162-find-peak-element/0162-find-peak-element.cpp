class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans=0;
        if (n == 1) {
            return 0;
        }
        while (low < high) {
            int mid = (low + high) / 2;

            if (nums[mid] < nums[mid + 1]) {
                ans = mid + 1;
                low = mid + 1;
            } else {
                high = mid ;
            }
        }
        return ans;
    }
};