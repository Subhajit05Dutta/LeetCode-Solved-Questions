class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0, r = 0, s = 0;
        for (int i = 0; i < moves.size(); i++) {
            if (moves[i] == 'L') {
                l++;
            } else if (moves[i] == 'R') {
                r++;
            } else {
                s++;
            }
        }
        if (l > r) {
            l += s;
        } else {
            r += s;
            return r - l;
        }
        return l - r;
    }
};