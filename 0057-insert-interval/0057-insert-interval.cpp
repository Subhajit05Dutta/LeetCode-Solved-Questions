class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int mini = newInterval[0];
        int maxi = newInterval[1];
        int i = 0;
        // Intervals completely before newInterval
        while (i < n && intervals[i][1] < mini) {
            ans.push_back(intervals[i]);
            i++;
        }
        // Merge overlapping intervals
        while (i < n && intervals[i][0] <= maxi) {
            mini = min(mini, intervals[i][0]);
            maxi = max(maxi, intervals[i][1]);
            i++;
        }
        ans.push_back({mini, maxi});

        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};