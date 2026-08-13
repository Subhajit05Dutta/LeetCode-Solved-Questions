class Solution {
public:
    int count(vector<int>& weights, int mid) {
        int cnt = 1;
        int rem = mid;
        for (int i = 0; i < weights.size(); i++) {
            if (rem >= weights[i]) {
                rem -= weights[i];
            } else {
                cnt += 1;
                rem = mid - weights[i];
            }
        }
        return cnt;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = 0;
        int sum = 0;
        for (int X : weights) {
            sum += X;
            low = max(low, X);
        }
        int high = sum;
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int req_days = count(weights, mid);
            if (req_days <= days) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};