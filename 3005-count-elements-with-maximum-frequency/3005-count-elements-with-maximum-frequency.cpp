class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int i : nums) {
            mpp[i]++;
        }
        int maxi = 0;
        for (auto& it : mpp) {
            maxi = max(maxi, it.second);
        }
        int cnt = 0;
        for (auto& it : mpp) {
            if (it.second == maxi) {
                cnt += maxi;
            }
        }
        return cnt;
    }
};