class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> best(n, vector<int>(m, -1));

        int start_health = health - grid[0][0];
        if (start_health <= 0)
            return false;

        queue<pair<int, pair<int, int>>> q;
        q.push({start_health, {0, 0}});
        best[0][0] = start_health;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        while (q.size() > 0) {

            int curr_health = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            // Destination reached with positive health
            if (r == n - 1 && c == m - 1)
                return true;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                    continue;

                int new_health = curr_health - grid[nr][nc];

                if (new_health <= 0)
                    continue;

                // Visit only if we have more health than before
                if (new_health > best[nr][nc]) {
                    best[nr][nc] = new_health;
                    q.push({new_health, {nr, nc}});
                }
            }
        }
        return false;
    }
};