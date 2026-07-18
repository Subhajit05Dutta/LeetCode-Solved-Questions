class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; i++) {
            string word = "";
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }
            if(word.length()!=0){
            reverse(word.begin(), word.end());
            ans = ans + " " + word;
            }
        }
        return ans.substr(1);
    }
};
/*
int n= s.length();
        string str[n];

        int j=n-1;
        int end=n-1;
        while(j>=0){
            if(s[j]!=' '){
                j--;
            }
            else if(s[j]==' '){
                str=str+s(j+1,end);
                end=j-1;
                j=j-1;
            }
        }
*/
