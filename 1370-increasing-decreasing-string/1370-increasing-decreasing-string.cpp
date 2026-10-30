class Solution {
public:
    string sortString(string s) {
        int n = s.size();
        string ans = "";
        unordered_map<char, int> mp;
        set<char> st;
        for (char ch : s) {
            mp[ch]++;
            st.insert(ch);
        }

        while (!mp.empty()) {
            // Increasing order
            for (auto x : st) {
                if (mp.find(x)!=mp.end() ) {
                    ans += x;
                    mp[x]--;
                    if(mp[x]==0){
                        mp.erase(x);
                    }
                }
            }

            if (mp.empty()) {
                break;
            }

            // Decreasing order
            for (auto it = st.rbegin(); it != st.rend(); it++) {
                if (mp.find(*it) != mp.end()) {
                    ans += *it;
                    mp[*it]--;
                    if (mp[*it] == 0) {
                        mp.erase(*it);
                    }
                }
            }
        }
        return ans;
    }
};