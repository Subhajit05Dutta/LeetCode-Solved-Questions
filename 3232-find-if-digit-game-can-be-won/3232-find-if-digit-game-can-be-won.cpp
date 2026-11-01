class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int s_sum = 0, d_sum = 0;
        for (int i : nums) {
            if (i < 10)
                s_sum += i;
            else
                d_sum += i;
        }
        return (s_sum == d_sum) ? false : true;
    }
};