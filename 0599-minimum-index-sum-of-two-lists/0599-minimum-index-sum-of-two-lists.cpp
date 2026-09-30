class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1,
                                  vector<string>& list2) {
        unordered_map<string, int> mpp1;
        unordered_map<string, int> mpp2;
        int i = 0;
        while (i < list1.size()) {
            mpp1[list1[i]] = i;
            i++;
        }
        i = 0;
        while (i < list2.size()) {
            mpp2[list2[i]] = i;
            i++;
        }
        vector<string> ans;
        int mini = INT_MAX;
        for (auto& it : mpp1) {
            if (mpp2.find(it.first) != mpp2.end()) {
                mini = min(mini, (it.second + mpp2[it.first]));
            }
        }
        for (auto& it : mpp1) {
            if (mpp2.find(it.first) != mpp2.end()) {
                if (it.second + mpp2[it.first] == mini) {
                    ans.push_back(it.first);
                }
            }
        }
        return ans;
    }
};