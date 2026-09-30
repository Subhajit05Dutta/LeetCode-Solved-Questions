class Solution {
public:
    vector<int> ans;
    void getdigit(int n) {
        vector<int> res;
        while (n > 0) {
            int rem = n % 10;
            res.push_back(rem);
            n /= 10;
        }
        for (int i = res.size() - 1; i >= 0; i--) {
            ans.push_back(res[i]);
        }
        return;
    }
    vector<int> separateDigits(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 9) {
                ans.push_back(nums[i]);
            } else {
                getdigit(nums[i]);
            }
        }
        return ans;
    }
};