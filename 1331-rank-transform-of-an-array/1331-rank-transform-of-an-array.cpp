class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        // Creates another array
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = arr[i];
        }
        // Sort it
        sort(ans.begin(), ans.end());
        // Create a map to store rank
        int r = 1;
        unordered_map<int, int> mpp;
        // Assign rank to each element
        for (int num : ans) {
            if (mpp.find(num) == mpp.end()) {
                mpp[num] = r;
                r++;
            }
        }
        // Iterate each element in arr and replace them with their rank
        for (int& num : arr) {
            num = mpp[num];
        }
        return arr;
    }
};