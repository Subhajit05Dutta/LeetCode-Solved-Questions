class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n=s.size();
        int l=0,r=n-1;
        while(l<r){
            if(!isalpha(s[l])){
                l++;
            }
            else if(isalpha(s[l])){
                while(!isalpha(s[r])){
                    r--;
                }
                swap(s[l],s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
};