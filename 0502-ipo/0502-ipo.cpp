class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> proj; //{capital,profit}
        for (int i = 0; i < n; i++) {
            proj.push_back({capital[i], profits[i]});
        }
        // Sort it according to capital ,if capital is same sort it according to
        // profit
        sort(proj.begin(), proj.end());
        priority_queue<int> pq;
        int idx = 0;
        while (k--) {
            while (idx < n) {
                if (proj[idx].first > w)
                    break;
                pq.push(proj[idx].second);
                idx++;
            }

            // No choices are left
            if (pq.empty()) {
                return w;
            }

            else {
                int pro = pq.top();
                pq.pop();
                w = w + pro;
            }
        }
        return w;
    }
};