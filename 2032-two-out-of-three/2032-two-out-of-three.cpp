class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2,
                              vector<int>& nums3) {
        unordered_set<int> st1;
        unordered_set<int> st2;
        unordered_set<int> st3;
        unordered_set<int> ans;

        for (int i : nums1) {
            st1.insert(i);
        }
        for (int i : nums2) {
            st2.insert(i);
        }
        for (int i : nums3) {
            st3.insert(i);
        }

        for (int i : st1) {
            if (st2.find(i) != st2.end() || st3.find(i) != st3.end()) {
                ans.insert(i);
            }
        }
        for (int i : st2) {
            if (st1.find(i) != st1.end() || st3.find(i) != st3.end()) {
                ans.insert(i);
            }
        }

        vector<int> res;
        for (int i : ans) {
            res.push_back(i);
        }
        return res;
    }
};