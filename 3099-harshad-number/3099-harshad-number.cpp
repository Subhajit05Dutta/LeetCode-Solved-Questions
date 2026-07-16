class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int n) {
        int x=n;
        int sum=0;
        while(x!=0){
            int rem=x%10;
            sum+=rem;
            x/=10;
        }
        if(n%sum==0){
            return sum;
        }
        return -1;

    }
};