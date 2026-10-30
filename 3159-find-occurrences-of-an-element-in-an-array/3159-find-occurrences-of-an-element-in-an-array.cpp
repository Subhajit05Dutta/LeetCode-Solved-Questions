class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries,
                                     int x) {
        vector<int> indices;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                indices.push_back(i);
            }
        }

        int n = queries.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            int occ = queries[i];

            if (occ <= indices.size()) {
                ans[i] = indices[occ - 1];
            }
        }

        return ans;
    }
};