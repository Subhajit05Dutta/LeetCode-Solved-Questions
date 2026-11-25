class Solution {
    // Builds the prefix hash array to allow O(1) subarray hash extraction
    vector<unsigned long long> computeHash(const vector<int>& nums) {
        vector<unsigned long long> hash(nums.size() + 1, 0);
        unsigned long long p =
            131071; // Prime base larger than max element (1e5)

        for (int i = 0; i < nums.size(); i++) {
            // unsigned long long naturally handles modulo 2^64 upon overflow
            hash[i + 1] = (hash[i] + (unsigned long long)nums[i]) * p;
        }
        return hash;
    }

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int lo = 1, hi = n;
        vector<unsigned long long> hash = computeHash(nums);
        int ans = hi;

        // Precompute powers of our base to avoid recalculating in the check
        // loop
        vector<unsigned long long> power(n + 1, 1);
        unsigned long long p = 131071;
        for (int i = 1; i <= n; i++) {
            power[i] = power[i - 1] * p;
        }

        // Returns true if there is ANY subarray of size 'len' that appears
        // exactly once
        auto check = [&](int len) {
            unordered_map<unsigned long long, int> mp;

            // Slide window of size 'len' across the array
            for (int i = len; i <= n; i++) {
                // O(1) Subarray Hash Extraction: Hash[R] - Hash[L-1] *
                // Base^Length
                unsigned long long curHash =
                    hash[i] - hash[i - len] * power[len];
                mp[curHash]++;
            }

            // Check if any subarray had a frequency of exactly 1
            for (auto& it : mp) {
                if (it.second == 1) {
                    return true;
                }
            }
            return false;
        };

        // Binary Search for the minimum valid length
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(mid)) {
                ans = mid;    // Record the valid length
                hi = mid - 1; // Try to find a smaller one
            } else {
                lo =
                    mid + 1; // Current length failed, we need a longer subarray
            }
        }
        return ans;
    }
};