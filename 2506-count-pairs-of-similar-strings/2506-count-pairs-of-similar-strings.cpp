class Solution {
public:
    int similarPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size() - 1; i++) {
            unordered_set<char> st1;
            for (char ch : words[i]) {
                st1.insert(ch);
            }
            for (int j = i + 1; j < words.size(); j++) {
                unordered_set<char> st2;
                for (char ch : words[j]) {
                    st2.insert(ch);
                }

                if (st1 == st2) {
                    count++;
                }
            }
        }
        return count;
    }
};