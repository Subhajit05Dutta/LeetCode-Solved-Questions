class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int st = 1;
        int i = 0;
        int ans = 0;
        while (i < n) {
            if (arr[i] == st) {
                st++;
                i++;
            } else {
                k--;
                if (k == 0) {
                    ans = st;
                    break;
                }
                st++;
            }
        }
        if (ans == 0 && i == n) {
            ans = arr[n - 1] + k;
        }
        return ans;
    }
};