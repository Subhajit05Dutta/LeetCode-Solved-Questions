class Solution {
public:
    bool fun(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        int m = board.size();
        int n = board[0].size();

        // Out of Bounds
        if (i >= m || i < 0 || j < 0 || j >= n) {
            return false;
        }
        if (board[i][j] != word[idx]) {
            return false;
        }
        // Entire word matched
        if (idx == word.size() - 1) {
            return true;
        }

        // Mark visited
        char temp = board[i][j];
        board[i][j] = '#';

        bool found = fun(board, word, i - 1, j, idx + 1) ||
                     fun(board, word, i, j + 1, idx + 1) ||
                     fun(board, word, i + 1, j, idx + 1) ||
                     fun(board, word, i, j - 1, idx + 1);

        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (fun(board, word, i, j, 0) == true) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};