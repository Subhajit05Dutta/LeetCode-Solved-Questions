class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, h = n - 1;
        int f = -1, la = -1;
        while (l <= h) {
            int m = (l + h) / 2;
            if (nums[m] == target) {
                f = m;
                h = m - 1;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        l = 0, h = n - 1;
        while (l <= h) {
            int m = (l + h) / 2;
            if (nums[m] == target) {
                la = m;
                l = m + 1;
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return {f, la};
    }
};
/*
int first = -1, last = -1;
        int n = nums.size();

        // Finding First occurance
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                first = mid;
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // Finding last occurance
        low = 0;
        high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                last = mid;
                low = mid + 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return {first, last};*/