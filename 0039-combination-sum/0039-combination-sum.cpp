class Solution {
public:
    vector<vector<int>>ans;
    void fun(vector<int>& candidates, int target,int idx,int n,int sum,vector<int>&temp){
        if(idx==n){
            return;
        }
        else if(sum==target){
            ans.push_back(temp);
            return;
        }
        fun(candidates,target,idx+1,n,sum,temp);
        if(sum+candidates[idx]<=target){
            temp.push_back(candidates[idx]);
            sum+=candidates[idx];
            fun(candidates,target,idx,n,sum,temp);
            sum-=candidates[idx];
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>temp;
        fun(candidates,target,0,n,0,temp);
        return ans;
    }
};