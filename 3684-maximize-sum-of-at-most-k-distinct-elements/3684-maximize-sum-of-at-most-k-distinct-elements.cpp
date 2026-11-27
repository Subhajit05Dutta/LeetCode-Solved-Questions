class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        priority_queue<int> pq;
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (st.find(nums[i]) == st.end()) {
                pq.push(nums[i]);
                st.insert(nums[i]);
            }
        }
        vector<int> ans;
        while (pq.size() != 0 && ans.size() < k) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};