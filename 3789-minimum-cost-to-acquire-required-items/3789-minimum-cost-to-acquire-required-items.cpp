class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        long long res = 0;
        int mn = min(need1, need2);
        int mx = max(need1, need2);
        long long pos1 = costBoth * 1LL * mx;
        long long pos2 = costBoth * 1LL * mn;
        if (mx == need1) {
            pos2 += (mx - mn) * 1LL * cost1;
        }
        if (mx == need2) {
            pos2 += (mx - mn) * 1LL * cost2;
        }
        long long pos3 = cost1 * 1LL * need1 + cost2 * 1LL * need2;
        return min({pos1, pos2, pos3});
    }
};