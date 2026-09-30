class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string>res(n);
        vector<pair<int,int>>nums;
        for(int i=0;i<n;i++){
            nums.push_back({score[i],i});
        }
        sort(nums.rbegin(),nums.rend());
        int rank=1;
        for(auto&it:nums){
            if(rank==1){
                res[it.second]="Gold Medal";
            }
             else if(rank==2){
                res[it.second]="Silver Medal";
            }
             else if(rank==3){
                res[it.second]="Bronze Medal";
            }
            else{
                res[it.second]=to_string(rank);
            }
            rank++;
        }
        return res;
    }
};