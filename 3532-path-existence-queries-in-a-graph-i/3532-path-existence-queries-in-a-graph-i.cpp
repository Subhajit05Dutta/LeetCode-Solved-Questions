class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py)
            parent[px] = py;
    }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        DSU dsu(n);

        pair<int, int> temp = pq.top();

        while (!pq.empty()) {
            pair<int, int> curr = pq.top();
            pq.pop();

            if (abs(temp.first - curr.first) <= maxDiff) {
                dsu.merge(temp.second, curr.second);
            }

            temp = curr;
        }

        vector<bool> sol;

        for (auto& it : queries) {
            sol.push_back(dsu.find(it[0]) == dsu.find(it[1]));
        }

        return sol;
    }
};
/*
//Approach which can be applicable
vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
vector<vector<int>>& queries) { vector<bool>ans; for(int
i=0;i<queries.size();i++){ int a=queries[i][0]; int b=queries[i][1]; int
Diff=abs(nums[a]-nums[b]); if(Diff<=maxDiff){ ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
*/