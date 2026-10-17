class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            int num = nums[i];
            while (num > 0) {
                sum += (num % 10);
                num /= 10;
            }
            mpp[nums[i]] = sum;
        }
        // Using Comparator function sort them
        sort(temp.begin(), temp.end(), [&](int a, int b) {
            if (mpp[a] == mpp[b]) {
                return a < b;
            }
            return mpp[a] < mpp[b];
        });

        unordered_map<int, int> idx;
        for (int i = 0; i < n; i++) {
            idx[nums[i]] = i;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != temp[i]) {
                cnt++;

                int j = idx[temp[i]];

                // Swap the elements
                swap(nums[i], nums[j]);

                // Update their positions
                idx[nums[j]] = j;
                idx[nums[i]] = i;
            }
        }
        return cnt;
    }
};