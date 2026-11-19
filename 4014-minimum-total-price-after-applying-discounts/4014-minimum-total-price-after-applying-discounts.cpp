class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());
        int n=min(prices.size(),discounts.size());
        double sum = 0.0;
        int i = 0;
        for (; i < n; i++) {
            double val = (double)prices[i] * (100 - discounts[i]) / 100.0;
            sum += val;
        }
        while (i < prices.size()) {
            sum += prices[i];
            i++;
        }
        return sum;
    }
};