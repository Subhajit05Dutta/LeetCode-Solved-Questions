class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        string ans="";
        for(int i=0;i<words.size();i++){
            string word=words[i];
            int j=0,k=word.size()-1;
            bool ispalindrome=true;
            while(j<k){
                if(word[j]==word[k]){
                    j++;
                    k--;
                }
                else{
                    ispalindrome=false;
                    break;
                }
            }
            if(ispalindrome==true){
                ans+=words[i];
                break;
            }
        }
        return ans;
    }
};