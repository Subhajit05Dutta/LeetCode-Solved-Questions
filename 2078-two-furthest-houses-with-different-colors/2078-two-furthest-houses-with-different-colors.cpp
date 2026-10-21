class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int maxi=0;
        int l=0,r=n-1;
        while(colors[0]==colors[r]){
            r--;
        }
        while(colors[n-1]==colors[l]){
            l++;
        }
        return max(n-1-l,r);
    }
};