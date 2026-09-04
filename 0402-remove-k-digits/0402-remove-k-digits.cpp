class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n = nums.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && k > 0 && st.top() > nums[i]) {
                st.pop();
                k--;
            }
            st.push(nums[i]);
        }
        while (k > 0) {
            st.pop();
            k--;
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }
        ans = ans.substr(i);
        if (ans == "") {
            return "0";
        }
        return ans;
    }
};