class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {{'I', 1},   {'V', 5},   {'X', 10},
                                       {'L', 50},  {'C', 100}, {'D', 500},
                                       {'M', 1000}};
        int res = 0;
        int i = 0, j = 1;
        while(j<s.length()){
            if(mp[s[i]]<mp[s[j]]){
                res=res+(mp[s[j]]-mp[s[i]]);
                i=i+2;
                j=j+2;
            }
            else{
                res=res+mp[s[i]];
                i++;
                j++;
            }
        }
        // If last character is left
        if(i<s.length()){
            res+=mp[s[i]];
            i++;
        }
        return res;
    }
};

