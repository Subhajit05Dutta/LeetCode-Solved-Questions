class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            int val = asteroids[i];
            bool destroy = false;
            while (!st.empty() && val < 0 && st.top() > 0) {
                if (abs(st.top()) < abs(val)) {
                    st.pop();
                } else if (abs(st.top()) == abs(val)) {
                    destroy = true;
                    st.pop();
                    break;
                } else {
                    destroy = true;
                    break;
                }
            }
            if (destroy == false) {
                st.push(val);
            }
        }
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};