class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        int n = mountain.size();
        vector<int> peak;
        if (n < 3) {
            return peak;
        }
        for (int i = 1; i < n - 1; i++) {
            if (mountain[i - 1] < mountain[i] &&
                mountain[i] > mountain[i + 1]) {
                peak.push_back(i);
            }
        }
        return peak;
    }
};