class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        for (int i = 0; i < words.size(); i++) {
            int size = words[i].size();
            if (words[i] == s.substr(0, size)) {
                cnt++;
            }
        }
        return cnt;
    }
};