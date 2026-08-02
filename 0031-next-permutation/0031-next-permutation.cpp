class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // Find Pivot
        int pivot = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] >= nums[i + 1]) {
                continue;
            } else {
                pivot = i;
                break;
            }
        }

        // Array is in descending order so we have to reverse it to get the next
        // permutation
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find the next greater elemnt than pivot
        for (int j = n - 1; j > pivot; j--) {
            if (nums[j] > nums[pivot]) {
                swap(nums[j], nums[pivot]);
                break;
            }
        }

        reverse(nums.begin() + pivot + 1, nums.end());

        return;
    }
};
