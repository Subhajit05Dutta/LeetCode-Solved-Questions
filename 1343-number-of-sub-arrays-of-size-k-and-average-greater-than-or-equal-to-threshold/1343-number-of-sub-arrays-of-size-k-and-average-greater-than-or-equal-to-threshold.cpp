class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        if ((sum / k) >= threshold) {
            cnt++;
        }
        int l = 0;
        int r = k;
        while (r < n) {
            sum += arr[r++];
            sum -= arr[l++];
            if ((sum / k) >= threshold) {
                cnt++;
            }
        }
        return cnt;
    }
};