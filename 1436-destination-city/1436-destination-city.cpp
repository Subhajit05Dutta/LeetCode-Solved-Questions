class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> mp;
        for (int i = 0; i < paths.size(); i++) {
            if (mp.find(paths[i][0]) == mp.end()) {
                mp[paths[i][0]] = 1;
                if (mp.find(paths[i][1]) == mp.end()) {
                    mp[paths[i][1]] = 0;
                }
            } else {
                if (mp[paths[i][0]] == 0) {
                    mp[paths[i][0]] = 1;

                    if (mp.find(paths[i][1]) == mp.end()) {
                        mp[paths[i][1]] = 0;
                    }
                }
            }
        }
        string ans="";
        for (auto& it:mp){
            if(it.second==0){
                ans=it.first;
                break;
            }
        }
        return ans;
    }
};