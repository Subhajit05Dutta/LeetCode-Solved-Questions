class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        // Hypothetically we consider the double of the array
        // because it is said to be circular
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i % n] >= st.top()) {
                st.pop();
            }
            if (i < n) {
                ans[i] = st.empty() ? -1 : st.top();
            }
            st.push(arr[i % n]);
        }
        return ans;
    }
};