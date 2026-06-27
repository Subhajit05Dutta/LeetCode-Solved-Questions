class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string ans1 = "";
        for (int i = 0; i < word1.size(); i++) {
            ans1 += word1[i];
        }
        string ans2 = "";
        for (int i = 0; i < word2.size(); i++) {
            ans2 += word2[i];
        }
        return (ans1 == ans2);
    }
};
/*
//Alternative Approach
bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string ans = "";
        for (int i = 0; i < word1.size(); i++) {
            string word = word1[i];
            int len = word.size();
            for (int j = 0; j < len; j++) {
                ans += word[j];
            }
        }
        int k = 0;
        for (int i = 0; i < word2.size(); i++) {
            string check = word2[i];
            for (int j = 0; j < check.size(); j++) {
                if (ans[k] != check[j]) {
                    return false;
                }
                k++;
            }
        }
        return (k==ans.size());
    }
*/