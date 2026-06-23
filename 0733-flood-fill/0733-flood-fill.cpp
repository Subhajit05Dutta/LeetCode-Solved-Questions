class Solution {
public:
    void DFS(vector<vector<int>>& image, int i, int j, int new_color,
             int old_color) {
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() ||
            image[i][j] == new_color || image[i][j] != old_color) {
            return;
        }
        image[i][j] = new_color;
        DFS(image, i - 1, j, new_color, old_color); // TOP
        DFS(image, i + 1, j, new_color, old_color); // Bottom
        DFS(image, i, j + 1, new_color, old_color); // RIGHT
        DFS(image, i, j - 1, new_color, old_color); // LEFT
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        DFS(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};