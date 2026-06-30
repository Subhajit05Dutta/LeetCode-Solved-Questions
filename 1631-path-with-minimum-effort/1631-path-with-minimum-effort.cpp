class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, {0, 0}});
        res[0][0] = 0;

        while (!pq.empty()) {
            int diff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if (diff > res[r][c]) {
                continue;
            }

            for (auto& it : dir) {
                int new_r = r + it[0];
                int new_c = c + it[1];

                if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m) {
                    int absdiff = abs(heights[r][c] - heights[new_r][new_c]);
                    int maxdiff = max(diff, absdiff);

                    if (res[new_r][new_c] > maxdiff) {
                        res[new_r][new_c] = maxdiff;
                        pq.push({maxdiff, {new_r, new_c}});
                    }

                }
            }
        }
        return res[n - 1][m - 1];
    }
};