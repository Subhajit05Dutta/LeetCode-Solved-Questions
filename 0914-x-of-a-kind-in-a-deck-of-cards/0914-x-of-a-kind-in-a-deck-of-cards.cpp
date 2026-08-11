class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mpp;
        for (int i : deck) {
            mpp[i]++;
        }
        int res = 0;
        for (auto& it : mpp) {
            res = gcd(res, it.second);
        }
        return res > 1;
    }
};