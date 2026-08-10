class Solution {
public:
    long long eating_time(vector<int>& piles, int t) {
        long long sum = 0;
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] % t == 0) {
                sum += (piles[i] / t);
            } else {
                sum += ((piles[i] / t) + 1);
            }
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = INT_MIN;
        for (int i = 0; i < piles.size(); i++) {
            high = max(high, piles[i]);
        }
        int ans = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            long long time = eating_time(piles, mid);
            if (time <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};