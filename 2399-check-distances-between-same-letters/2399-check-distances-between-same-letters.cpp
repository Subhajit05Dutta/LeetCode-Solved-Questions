class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            if(mpp.find(s[i])==mpp.end()){
                mpp[s[i]]=i;
            }
            else{
                int dist=i-mpp[s[i]]-1;
                if(dist!=distance[s[i]-'a']){
                    return false;
                }
            }
        }
        return true;
    }
};