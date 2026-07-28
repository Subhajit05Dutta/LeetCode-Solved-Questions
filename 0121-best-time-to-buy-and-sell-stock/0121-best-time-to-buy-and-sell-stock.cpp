class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int cost = nums[0];
        int maxprofit = 0;
        for (int i = 0; i < nums.size(); i++) {
            cost = min(cost, nums[i]);
            int profit = nums[i] - cost;
            maxprofit = max(maxprofit, profit);
        }
        return maxprofit;
    }
};