class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char>lower;
        set<char>upper;
        for(int i=0;i<word.size();i++){
            if(islower(word[i])){
                lower.insert(word[i]);
            }
            else{
                upper.insert(tolower(word[i]));
            }
        }
        int cnt=0;
        for(auto &it:lower){
            if(upper.find(it)!=upper.end()){
                cnt++;
            }
        }
        return cnt;
    }
};