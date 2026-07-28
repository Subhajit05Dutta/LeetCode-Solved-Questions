class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        string middle = "";
        if (n % 2 == 1) {
            middle += s[n / 2];
        }

        string half = "";
        vector<int> freq(26, 0);
        for (int i = 0; i < n / 2; i++) {
            freq[s[i] - 'a']++;
        }

        // Construct the lexicographically smallest first half
        for (int i = 0; i < 26; i++) {
            half.append(freq[i], char(i + 'a'));
        }

        string sec_half = half;
        reverse(sec_half.begin(), sec_half.end());

        return half + middle + sec_half;
    }
};