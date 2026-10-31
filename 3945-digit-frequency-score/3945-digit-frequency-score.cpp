class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int, int> mpp;
        while (n > 0) {
            int rem = n % 10;
            n /= 10;
            mpp[rem]++;
        }
        int sum = 0;
        for (auto& it : mpp) {
            int score = it.first * it.second;
            sum += score;
        }
        return sum;
    }
};