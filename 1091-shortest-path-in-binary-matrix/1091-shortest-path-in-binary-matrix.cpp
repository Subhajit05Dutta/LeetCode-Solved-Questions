class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int>src={0,0};
        vector<int>dest={n-1,m-1};

         // If source or destination is blocked
        if (grid[src[0]][src[1]] == 1 || grid[dest[0]][dest[1]] == 1)
            return -1;
        // If source == destination
        if (n==1 && m==1) {
            return 1;
        }

        // Queue will be : (dist,(row,col))
        queue<pair<int, pair<int, int>>> q;

        // Initialize all the distance matrix elements as infinity.
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = 1;
        q.push({1,{0,0}});

        // For Traversal
        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};

        while (!q.empty()) {
            int dis = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            for (int i = 0; i < 8; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];

                // Check validity
                if (newr >= 0 && newr < n && newc >= 0 && newc < m &&
                    grid[newr][newc] == 0 && dis + 1 < dist[newr][newc]) {
                    dist[newr][newc] = dis + 1;
                    if (newr == dest[0] && newc == dest[1]) {
                        return dis + 1;
                    }
                    q.push({dis + 1, {newr, newc}});
                }
            }
        }
        return -1;
    }
};