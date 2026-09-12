class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),
             [](const vector<int> &p1, const vector<int> &p2) {
                 return p1[0] > p2[0] ||
                        p1[0] == p2[0] && p1[1] < p2[1];
             });

        vector<vector< int>> sol;
        for (auto it : people) {
            sol.insert(sol.begin() + it[1], it);
        }
        return sol;
    }
};