class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        for (int i = 0; i < k; i++) {
            int maxi = INT_MIN;
            int idx = 0;
            for (int j = 0; j < gifts.size(); j++) {
                if (gifts[j] > maxi) {
                    idx = j;
                    maxi = gifts[j];
                }
            }
            int val = sqrt(maxi);
            gifts[idx] = val;
        }
        long long sum = 0;
        for (int i = 0; i < gifts.size(); i++) {
            sum += gifts[i];
        }
        return sum;
    }
};