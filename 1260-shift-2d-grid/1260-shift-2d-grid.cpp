class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r=grid.size();
        int c=grid[0].size();
        int sz=r*c;
        k=k%sz;

        vector<vector<int>>ans(r,vector<int>(c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int new_idx=i*c+j+k;
                int new_r=(new_idx/c)%r;
                int new_c=new_idx%c;

                ans[new_r][new_c]=grid[i][j];
            }
        }
        return ans;
    }
};