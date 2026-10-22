class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set< int> mp1;
        unordered_set< int> mp2;
        for (int i : nums1) {
            mp1.insert(i);
        }
        for (int i : nums2) {
            mp2.insert(i);
        }

        vector<vector<int>> ans;
        vector<int> res1;
        for (auto& it : mp1) {
            if (mp2.find(it) == mp2.end()) {
                res1.push_back(it);
            }
        }
        ans.push_back(res1);
        vector<int> res2;
        for (auto& it : mp2) {
            if (mp1.find(it) == mp1.end()) {
                res2.push_back(it);
            }
        }
        ans.push_back(res2);
        return ans;
    }
};