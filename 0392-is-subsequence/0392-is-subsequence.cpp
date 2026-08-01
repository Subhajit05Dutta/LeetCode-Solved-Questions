class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=t.size();
        int m=s.size();
        int i=0;
        int j=0;
        while(i<n){
            if(t[i]!=s[j]){
                i++;
            }else{
                j++;
                i++;
                if(j==m){
                    return true;
                }
            }

        }
        return (j==m);
    }
};