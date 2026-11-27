class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        double sum = 0.0;
        int cnt = 0;
        for (int i = n / 20; i < n - (n / 20); i++) {
            sum += arr[i];
            cnt++;
        }
        return sum / cnt;
    }
};