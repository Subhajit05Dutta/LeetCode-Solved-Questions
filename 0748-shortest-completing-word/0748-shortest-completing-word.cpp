class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {

        unordered_map<int, int> mp;
        for (int i = 0; i < licensePlate.size(); i++) {
            if (isalpha(licensePlate[i])) {
                mp[tolower(licensePlate[i]) - 'a']++;
            }
        }
        string ans = "";
        for (int i = 0; i < words.size(); i++) {
            int freq[26] = {0};
            for (int j = 0; j < words[i].size(); j++) {
                freq[words[i][j] - 'a']++;
            }
            bool include = true;
            for (auto& it : mp) {
                if (it.second > freq[it.first]) {
                    include = false;
                    break;
                }
            }
            if (include == true) {
                if (ans == "" || words[i].size() < ans.size()) {
                    ans = words[i];
                }
            }
        }
        return ans;
    }
};