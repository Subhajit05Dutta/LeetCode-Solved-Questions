class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int total = 0;
        int mini = 0;
        for (int ele : nums) {
            total += ele;
            mini = min(mini, total);
        }
        return (1 - mini);
    }
};