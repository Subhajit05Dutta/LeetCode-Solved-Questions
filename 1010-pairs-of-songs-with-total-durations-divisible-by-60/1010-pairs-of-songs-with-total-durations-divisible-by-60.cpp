class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt = 0;
        vector<int> rem(60, 0);
        for (int t : time) {
            int r = (t % 60 + 60) % 60;
            int need = (60 - r) % 60;
            if (rem[need]) {
                cnt += rem[need];
            }
            rem[r]++;
        }
        return cnt;
    }
};

/*
//Alternative Solution
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt = 0;
        int n = time.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((time[i] + time[j]) % 60 == 0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
*/