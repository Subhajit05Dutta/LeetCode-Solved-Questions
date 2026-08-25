class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<n;i++){
            int j=0,k=m-1;
            while(j<k){
                swap(image[i][j],image[i][k]);
                j++;
                k--;
            }

            for(int a=0;a<m;a++){
                if(image[i][a]==0){
                    image[i][a]=1;
                }
                else{
                     image[i][a]=0;
                }
            }
        }
        return image;
    }
};