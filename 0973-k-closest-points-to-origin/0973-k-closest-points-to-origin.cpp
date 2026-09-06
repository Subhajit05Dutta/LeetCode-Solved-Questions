class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq; // Max Heap
        int n = points.size();

        int j = 0;
        for (int i = 0; i < n; i++) {
            int x = points[i][0];
            int y = points[i][1];

            int dist = x * x + y * y;

            if (pq.size() < k) {
                pq.push({dist, i});
                j++;
            } else {
                if (pq.top().first > dist) {
                    pq.pop();
                    pq.push({dist, i});
                }
            }
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            int idx = pq.top().second;
            ans.push_back(points[idx]);
            pq.pop();
        }
        return ans;
    }
};