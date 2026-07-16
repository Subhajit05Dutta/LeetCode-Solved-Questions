class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int, string>> align(n);
        for (int i = 0; i < n; i++) {
            align[i] = {heights[i], names[i]};
        }
        sort(align.rbegin(), align.rend());
        vector<string> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = align[i].second;
        }
        return ans;
    }
};