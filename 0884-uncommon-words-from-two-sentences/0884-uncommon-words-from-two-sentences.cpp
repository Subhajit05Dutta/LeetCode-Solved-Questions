class Solution {
public:
    void store(string& s, unordered_map<string, int>& mpp) {
        string word = "";
        for (char ch : s) {
            if (ch == ' ') {
                mpp[word]++;
                word = "";
            } else {
                word += ch;
            }
        }
        //Last Word
        mpp[word]++;
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mpp;
        store(s1, mpp);
        store(s2, mpp);
        vector<string> res;
        for (auto& it : mpp) {
            if (it.second == 1) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};