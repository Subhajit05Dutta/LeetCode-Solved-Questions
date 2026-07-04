class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        for (int i : arr1) {
            mpp[i]++;
        }
        for (int j : arr2) {
            while (mpp[j] > 0) {
                ans.push_back(j);
                mpp[j]--;
            }
        }
        vector<int> ans2;
        for (int i : arr1) {
            while (mpp[i] > 0) {
                ans2.push_back(i);
                mpp[i]--;
            }
        }
        sort(ans2.begin(), ans2.end());
        for (int i = 0; i < ans2.size(); i++) {
            ans.push_back(ans2[i]);
        }
        return ans;
    }
};