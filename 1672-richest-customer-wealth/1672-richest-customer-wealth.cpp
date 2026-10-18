class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = 0;
        for (int i = 0; i < accounts.size(); i++) {
            int size = accounts[i].size();
            int sum = 0;
            for (int j = 0; j < size; j++) {
                sum += accounts[i][j];
            }
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};