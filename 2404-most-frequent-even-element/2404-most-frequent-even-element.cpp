class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int ans = -1;
        int maxi = 0;
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                mpp[nums[i]]++;
            }
        }
        for (auto it : mpp) {
            if (it.second > maxi) {
                maxi = it.second;
                ans = it.first;
            } else if (it.second == maxi && it.first < ans) {
                ans = it.first;
            }
        }
        return ans;
    }
};