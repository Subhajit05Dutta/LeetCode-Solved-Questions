class Solution {
public:
    bool digitsumprod(int n){
        int num=n;
        int sum=0;
        int prod=1;
        while(n>0){
            int rem=n%10;
            prod*=rem;
            sum+=rem;
            n/=10;
        }
        if(num%(sum+prod)==0){
            return true;
        }
        return false;
    }
    bool checkDivisibility(int n) {
        bool ans=digitsumprod(n);
        return ans;
    }
};