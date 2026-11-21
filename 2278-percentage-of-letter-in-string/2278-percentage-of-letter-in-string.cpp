class Solution {
public:
    int percentageLetter(string s, char letter) {
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==letter){
                cnt++;
            }
        }
        int len=s.size();
        return (cnt*100/len);
    }
};