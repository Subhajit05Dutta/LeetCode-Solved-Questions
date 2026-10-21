class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi = 0;
        for (int i = 0; i < sentences.size(); i++) {
            int size = sentences[i].size();
            int j = 0;
            int cnt = 0;
            while (j < size) {
                while (j < size && sentences[i][j] != ' ') {
                    j++;
                }
                cnt++;
                j++;
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};