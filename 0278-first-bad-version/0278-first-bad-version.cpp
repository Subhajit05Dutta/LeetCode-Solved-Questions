// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=0,h=n;
        int ans=1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(isBadVersion(m)==true){
                ans=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};