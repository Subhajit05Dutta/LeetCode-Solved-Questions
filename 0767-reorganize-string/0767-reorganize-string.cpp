class Solution {
public:
    string reorganizeString(string s) {
        string res = "";
        unordered_map<char, int> mpp;
        for (char ch : s) {
            mpp[ch]++;
        }
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        for (auto it : mpp) {
            pq.push({it.second, it.first});
        }
        int step = 0;
        while (!pq.empty()) {
            pair<int, char> p = pq.top();
            pq.pop();
            if (step == 0 || res[step - 1] != p.second) {
                res.push_back(p.second);
                step++;
                p.first--;
                if (p.first > 0) {
                    pq.push(p);
                }
            } else {
                if (pq.empty()) {
                    return "";
                }
                pair<int, char> p2 = pq.top();
                pq.pop();
                res.push_back(p2.second);
                step++;
                p2.first--;
                if (p2.first > 0) {
                    pq.push(p2);
                }
                pq.push(p);
            }
        }
        return res;
    }
};