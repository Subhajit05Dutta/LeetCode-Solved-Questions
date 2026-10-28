class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int ans1 = 0, ans2 = 0;
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        for (int i : nums1) {
            mp1[i]++;
        }
        for (int i : nums2) {
            mp2[i]++;
        }
        for (auto& it : mp1) {
            if (mp2.find(it.first) != mp2.end()) {
                ans1 += it.second;
            }
        }
        for (auto& it : mp2) {
            if (mp1.find(it.first) != mp1.end()) {
                ans2 += it.second;
            }
        }
        return {ans1, ans2};
    }
};