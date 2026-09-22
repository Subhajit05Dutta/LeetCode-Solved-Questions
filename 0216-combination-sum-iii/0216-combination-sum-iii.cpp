class Solution {
public:
    void fun(vector<vector<int>>& ans, vector<int>& res, int i, int k, int n) {
        if(k==0){
            if(n==0){
                ans.push_back(res);
            }
            return;
        }
        if(i<=9){
        res.push_back(i);
        fun(ans,res,i+1,k-1,n-i);
        res.pop_back();

        fun(ans,res,i+1,k,n);
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> res;
        fun(ans, res, 1, k, n);
        return ans;
    }
};