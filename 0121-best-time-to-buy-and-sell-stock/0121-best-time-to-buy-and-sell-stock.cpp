class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mxprofit=0;
        int mini_cost=prices[0];
        for(int i=0;i<prices.size();i++){
            if(prices[i]<mini_cost){
                mini_cost=prices[i];
            }
            int profit=prices[i]-mini_cost;
            mxprofit=max(mxprofit,profit);
        }
        return mxprofit;
    }
};