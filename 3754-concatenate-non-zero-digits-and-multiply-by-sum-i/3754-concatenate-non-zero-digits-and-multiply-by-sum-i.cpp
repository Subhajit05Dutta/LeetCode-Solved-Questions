class Solution {
public:
    long long sumAndMultiply(int n) {
        int x=0;
        int sum=0;
        while(n!=0){
            int rem=n%10;
            if(rem!=0){
                sum+=rem;
                x=x*10+rem;
            }
            n=n/10;
        }
        long long num=0;
        while(x!=0){
            int rem=x%10;
            num=num*10+rem;
            x/=10;
        }
        return num*sum;
    }
};