class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[26]={0};
        /*
        Frequency Count + Greedy
        Count all characters.
        Since 'l' and 'o' appear twice in "balloon",
        use freq['l']/2 and freq['o']/2.
        The minimum available count among (b, a, l/2, o/2, n) is the answer.
        */
        for(int i=0;i<text.size();i++){
            freq[text[i]-'a']++;
        }

        return min({freq[0],freq[1],freq['l'-'a']/2,freq['o'-'a']/2,freq['n'-'a']});
    }
};