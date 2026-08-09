class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        int l=0,r=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cnt=0;

        while(l<n && r<m){
            if(s[r]>=g[l]){
                cnt++;
                l++;
                r++;
            }
            else{
                r++;
            }
        }
        return cnt;
    }
};