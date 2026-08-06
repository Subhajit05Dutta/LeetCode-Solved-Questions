class Solution {
public:
    int product(int n){
        int prod=1;
        int x=n;
        while(x>0){
            int rem=x%10;
            prod*=rem;
            x=x/10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        while(true){
            int res=product(n);
            if(res%t==0){
                return n;
            }
            else{
                n++;
            }
        }
        return 0;
    }
};