class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_set<int> st;
        for (int i : nums) {
            if(st.count(i)){
                continue;
            }
            st.insert(i);
            if (pq.size() < 3) {
                pq.push(i);
            } else if (i > pq.top()) {
                pq.pop();
                pq.push(i);
            }
        }
        if (pq.size() < 3) {
            while (pq.size() != 1) {
                pq.pop();
            }
            return pq.top();
        }
        return pq.top();
    }
};