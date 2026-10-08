class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> mp;
        int total = 0;
        for (auto& d : dominoes) {
            int a = min(d[0], d[1]);
            int b = max(d[0], d[1]);
            int key = a * 10 + b;
            total += mp[key];
            mp[key]++;
        }
        return total;
    }
};

/*
//Alternative Approach
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int total = 0;
        for (int i = 0; i < dominoes.size() - 1; i++) {
            for (int j = i + 1; j < dominoes.size(); j++) {
                if ((dominoes[i][0] == dominoes[j][0] &&
                     dominoes[i][1] == dominoes[j][1]) ||
                    (dominoes[i][0] == dominoes[j][1] &&
                     dominoes[i][1] == dominoes[j][0])) {
                    total += 1;
                }
            }
        }
        return total;
    }
*/