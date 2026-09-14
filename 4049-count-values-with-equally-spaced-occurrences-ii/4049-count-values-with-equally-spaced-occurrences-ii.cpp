class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();

        // Store all positions of each number
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        int cnt = 0;
        for (auto& it : mp) {
            vector<int>& pos = it.second;
            // Need at least 3 occurrences
            if (pos.size() < 3) {
                continue;
            }
            // Difference between first two occurrences
            int diff = pos[1] - pos[0];

            bool special = true;

            // Check all consecutive gaps
            for (int i = 2; i < pos.size(); i++) {
                if (pos[i] - pos[i - 1] != diff) {
                    special = false;
                    break;
                }
            }

            if (special) {
                cnt++;
            }
        }
        return cnt;
    }
};