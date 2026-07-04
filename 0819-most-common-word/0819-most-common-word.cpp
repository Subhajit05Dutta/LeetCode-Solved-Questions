class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> mpp;
        unordered_set<string> ban(banned.begin(), banned.end());
        string word = "";
        for (int i = 0; i < paragraph.size(); i++) {
           if(isalpha(paragraph[i])){
                word += tolower(paragraph[i]);
            }
            else{
                if (!word.empty()) {
                    mpp[word]++;
                    word = "";
                }
            }
        }
        // Last Word
        if (!word.empty())
            mpp[word]++;

        int cnt = 0;
        string maxi = "";
        for (auto& it : mpp) {
            if (!ban.count(it.first) && it.second > cnt) {
                maxi = it.first;
                cnt = it.second;
            }
        }
        return maxi;
    }
};