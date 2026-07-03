class Solution {
public:
    int dist(vector<int>& a, vector<int>& b) {
        int dx = a[0] - b[0];
        int dy = a[1] - b[1];
        return dx * dx + dy * dy;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3,
                     vector<int>& p4) {
        vector<int> d = {
            dist(p1, p2), // d0
            dist(p1, p3), // d1
            dist(p1, p4), // d2
            dist(p2, p3), // d3
            dist(p2, p4), // d4
            dist(p3, p4)  // d5
        };
        sort(d.begin(), d.end());
        return d[0] > 0 && d[0] == d[1] && d[1] == d[2] && d[2] == d[3] &&
               d[4] == d[5];
    }
};