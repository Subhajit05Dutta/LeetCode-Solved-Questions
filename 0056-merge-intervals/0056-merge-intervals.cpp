class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int mini = intervals[0][0];
        int maxi = intervals[0][1];
        vector<vector<int>> ans;
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= maxi) {
                //mini=min(mini)
                maxi = max(maxi, intervals[i][1]);
            } else {
                vector<int> res(2);
                res[0] = mini;
                res[1] = maxi;
                ans.push_back(res);
                mini = intervals[i][0];
                maxi = intervals[i][1];
            }
        }
        vector<int> res(2);
        res[0] = mini;
        res[1] = maxi;
        ans.push_back(res);
        return ans;
    }
};