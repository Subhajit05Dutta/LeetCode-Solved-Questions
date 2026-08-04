class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res="";
        int i=0,j=0;
        int flag=0;
        while(i<word1.size()&&j<word2.size()){
            if(flag==0){
                res=res+word1[i++];
                flag=1;
            }
            else if(flag==1){
                res=res+word2[j++];
                flag=0;
            }
        }
        while(i<word1.size()){
            res+=word1[i];
            i++;
        }
        while(j<word2.size()){
            res+=word2[j];
            j++;
        }
        return res;
    }
};