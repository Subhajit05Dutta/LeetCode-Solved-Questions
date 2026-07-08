class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int it : nums) {
            mp[it]++;
        }
        // Min heap{freqency,element}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto it : mp) {
            pq.push({it.second, it.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

/*
//Alternative Approach
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int it : nums) {
            mp[it]++;
        }
        vector<pair<int, int>> freq;
        for (auto it : mp) {
            freq.push_back({it.second, it.first});
        }
        // This sorts in descending order.
        sort(freq.rbegin(), freq.rend());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(freq[i].second);
        }
        return ans;
    }
*/