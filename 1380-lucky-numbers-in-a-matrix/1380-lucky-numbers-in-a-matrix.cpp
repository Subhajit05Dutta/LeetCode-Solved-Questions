class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>ans;
        for(int i=0;i<m;i++){
            int mini=INT_MAX;
            int col=0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]<mini){
                    mini=matrix[i][j];
                    col=j;
                }
            }
            bool flag=true;
            for(int k=0;k<m;k++){
                if(matrix[k][col]>mini){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                ans.push_back(mini);
            }
        }
        return ans;
    }
};