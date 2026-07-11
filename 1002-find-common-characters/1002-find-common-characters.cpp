class Solution {
public:
    vector<int> count(string& s) {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }
        return freq;
    }
    vector<int> common(const vector<int>& a,const vector<int>& b) {
        vector<int> t(26, 0);
        for (int i = 0; i < 26; i++) {
            t[i] = min(a[i], b[i]);
        }
        return t;
    }
    vector<string> commonChars(vector<string>& words) {
        vector<int> last = count(words[0]);
        for (int i = 1; i < words.size(); i++) {
            last = common(last, count(words[i]));
        }
        vector<string> res;
        for (int i = 0; i < 26; i++) {
            while (last[i] > 0) {
                // string(1, ch) means create a string of length 1 containing
                // ch.
                res.push_back(string(1, 'a' + i));
                last[i]--;
            }
        }
        return res;
    }
};