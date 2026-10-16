class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int minus = 0, plus = 0;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i][1] == '+') {
                plus++;
            } else {
                minus--;
            }
        }
        return plus + minus;
    }
};