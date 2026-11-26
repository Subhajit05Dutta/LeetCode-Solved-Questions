class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> light(101, 0);
        for (int i = 0; i < bulbs.size(); i++) {
            light[bulbs[i]]= !light[bulbs[i]];
        }
        vector<int> ans;
        for (int i = 0; i < 101; i++) {
            if (light[i] == 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};