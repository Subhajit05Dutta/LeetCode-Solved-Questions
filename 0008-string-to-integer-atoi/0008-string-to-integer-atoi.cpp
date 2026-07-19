class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        long long res=0;
        while(s[i]==' '){
            i++;
        }
        if(i==n){
            return 0;
        }
        int sign=1;
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }

        while(i<n&&isdigit(s[i])){
            int num=(int)(s[i]-'0');
            res=res*10+num;
            if(sign*res<INT_MIN){
                return INT_MIN;
            }
            if(sign*res>INT_MAX){
                return INT_MAX;
            }
            i++;
        }
        return (int)sign*res;
    }
};
/*
//Alternative Approach
        int myAtoi(string s) {
            long res = 0;
            int sign = 1;
            int i = 0;
            while (i < s.length() && s[i] == ' ') {
                i++;
            }
            if (s[i] == s.length()) {
                return 0;
            }
            if (s[i] == '-') {
                sign = -1;
                i++;
            } else if (s[i] == '+') {
                i++;
            }

            while (i < s.length() &&   isdigit(s[i]) ) {
                res = res * 10 + (s[i] - '0');
                if (res * sign > INT_MAX) {
                    return INT_MAX;
                }
                if (res * sign < INT_MIN) {
                    return INT_MIN;
                }

                i++;
            }
            return (int)(sign * res);
        }
*/

