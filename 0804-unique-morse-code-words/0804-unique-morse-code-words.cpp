class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morseCode = {
            ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
            "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
            "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
            "...-", ".--",  "-..-", "-.--", "--.."};
        unordered_set<string> unique;
        for (const string& word : words) {
            string morseRepresentation = "";
            for (char ch : word) {
                morseRepresentation += morseCode[ch - 'a'];
            }
            unique.insert(morseRepresentation);
        }
        return unique.size();
    }
};