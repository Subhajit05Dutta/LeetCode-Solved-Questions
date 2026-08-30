class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = 0;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] < mini) {
                l = i;
                mini = nums[i];
            }
            if (nums[i] > maxi) {
                h = i;
                maxi = nums[i];
            }
        }
        // Make l the leftmost index and h the rightmost index
        if (l > h)
            swap(l, h);
        // 1. Remove both from the left
        int left = h + 1;
        // 2. Remove both from the right
        int right = n - l;
        // 3. Remove l from left and h from right
        int both = (l + 1) + (n - h);

        return min({left,right,both});
    }
};