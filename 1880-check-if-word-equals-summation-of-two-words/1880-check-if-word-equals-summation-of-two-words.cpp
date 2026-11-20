class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int n1 = 0;
        for (int i = 0; i < firstWord.size(); i++) {
            n1 = n1 * 10 + (firstWord[i] - 'a');
        }
        int n2 = 0;
        for (int i = 0; i < secondWord.size(); i++) {
            n2 = n2 * 10 + (secondWord[i] - 'a');
        }
        int n3 = 0;
        for (int i = 0; i < targetWord.size(); i++) {
            n3 = n3 * 10 + (targetWord[i] - 'a');
        }
        return (n1 + n2) == n3;
    }
};