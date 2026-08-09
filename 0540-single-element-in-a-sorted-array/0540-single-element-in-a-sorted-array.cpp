class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (mid % 2 == 0) {
                if (mid + 1 == n) {
                    return nums[low];
                } else if (nums[mid] == nums[mid + 1]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                if (mid - 1 == -1) {
                    return nums[low];
                }
                if (nums[mid] == nums[mid - 1]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return nums[low];
    }
};

/*
//Alternative Approach
    int singleNonDuplicate(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans^nums[i];
        }
        return ans;
    }
*/