class Solution {
public:
    int findfreq(vector<int>& freq) {
        int maxi = 0;
        for (int i = 0; i < 26; i++) {
            maxi = max(maxi, freq[i]);
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        int low = 0, high = 0;
        int n = s.size();
        vector<int> freq(26, 0);
        int maxfreq = 0;
        int res = 0;
        while (high < n) {
            freq[s[high] - 'A']++;
            maxfreq = findfreq(freq);
            int len = high - low + 1;
            int diff = len - maxfreq;
            while (diff > k) {
                freq[s[low] - 'A']--;
                low++;
                maxfreq = findfreq(freq);
                len = high - low + 1;
                diff = len - maxfreq;
            }
            // Either diff<k or diff==k
            len = high - low + 1;
            res = max(res, len);
            high++;
        }
        return res;
    }
};
