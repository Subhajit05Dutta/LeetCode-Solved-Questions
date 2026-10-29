class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operations;
        int idx = 0;
        for (int i = 1; i <= n; i++) {
            if (idx == target.size()) {
                break;
            }
            if (target[idx] == i) {
                operations.push_back("Push");
                idx++;
            } else {
                operations.push_back("Push");
                operations.push_back("Pop");
            }
        }
        return operations;
    }
};