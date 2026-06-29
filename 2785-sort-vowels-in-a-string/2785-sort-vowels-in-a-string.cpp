class Solution {
public:
    bool isvowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        return false;
    }
    string sortVowels(string s) {
        string vowel = "";
        for (int i = 0; i < s.size(); i++) {
            if (isvowel(s[i])) {
                vowel += s[i];
            }
        }
        sort(vowel.begin(),vowel.end());
        int j=0;
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])){
                s[i]=vowel[j++];
            }
        }
        return s;
    }
};