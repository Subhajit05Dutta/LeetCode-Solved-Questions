class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));
        // only one row or one column
        if (m == 1 || n == 1) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] = '.';
                }
            }
            return grid;
        }
        // Make first column free
        for (int i = 0; i < m; i++) {
            grid[i][0] = '.';
        }
        // Make last row free
        for (int j = 0; j < n; j++) {
            grid[m - 1][j] = '.';
        }
        return grid;
    }
};