class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        long long total = 0;
        unordered_map<int,int>freq;
        for (int i = 0; i < n ; i++) {
            int diff=i-nums[i];
            int goodpairs=freq[diff];
            total+=i-goodpairs;
            freq[diff]=goodpairs+1;
        }
        return total;
    }
};