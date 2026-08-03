class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, h = 0;
        int maximum = 0;
        unordered_map<int, int> mpp;
        while (h < n) {
            mpp[fruits[h]]++;
            while (mpp.size() > 2) {
                mpp[fruits[l]]--;
                if ((mpp[fruits[l]]) == 0) {
                    mpp.erase(fruits[l]);
                }
                l++;
            }
            if (mpp.size() == 2) {
                maximum = max(maximum, h - l + 1);
            }
            h++;
        }
        if(mpp.size()<2){
            return mpp[fruits[l]];
        }
        return maximum;
    }
};