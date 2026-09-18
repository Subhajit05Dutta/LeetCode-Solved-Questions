class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int i : nums) {
            mpp[i]++;
        }
        int rep, miss;
        for (int i = 1; i <= nums.size(); i++) {
            if (mpp.find(i) == mpp.end()) {
                miss = i;
            } else if (mpp[i] == 2) {
                rep = i;
            }
        }
        return {rep, miss};
    }
};