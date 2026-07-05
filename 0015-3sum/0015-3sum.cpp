class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++) {
            // This line is the key to avoiding duplicate triplets.
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1;
            int r = n - 1;
            int need = (-nums[i]);

            while (l < r) {

                if ((nums[l] + nums[r]) == need) {
                    vector<int> vec = {nums[i], nums[l], nums[r]};
                    ans.push_back(vec);
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r + 1]) {
                        r--;
                    }
                } else if ((nums[l] + nums[r]) < need) {
                    l++;
                } else {
                    r--;
                }
            }
            
        }
        return ans;
    }
};