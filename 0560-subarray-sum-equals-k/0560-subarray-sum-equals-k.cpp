class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int cnt = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int ques = sum - k;
            int freq = mpp[ques];
            cnt += freq;
            mpp[sum]++;
        }
        return cnt;
    }
};

/*
//Alternative Approach (Applicable only for positive numbers in sorted order)
int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int sum = 0;
        int cnt = 0;
        while (l < r) {
            sum += nums[r];
            if (sum == k)
                cnt++;
            else if (sum > k) {
                sum -= nums[l++];
                if (sum == k)
                    cnt++;
            }
            r++;
        }
        return cnt;
    }
*/