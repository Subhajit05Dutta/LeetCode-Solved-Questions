class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>st1;
        for(int i=0;i<allowed.size();i++){
           st1.insert(allowed[i]);
        }
        int cnt=0;
        for(int i=0;i<words.size();i++){
            unordered_set<char>st2;
            for(int j=0;j<words[i].size();j++){
                st2.insert(words[i][j]);
            }
            int flag=1;
            for(auto &it:st2){
                if(st1.find(it)==st1.end()){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                cnt+=1;
            }
        }
        return cnt;
    }
};