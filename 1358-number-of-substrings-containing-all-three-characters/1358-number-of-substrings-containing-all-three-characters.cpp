class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int left = 0;
        int count = 0;
        int count_char[3] = {0};
        for (int right = 0; right < n; right++) {
            count_char[s[right] - 'a']++;
            while (count_char[0] > 0 && count_char[1] > 0 &&
                   count_char[2] > 0) {
                count = count + (n - right);
                count_char[s[left] - 'a']--;
                left++;
            }
        }
        return count;
    }
};