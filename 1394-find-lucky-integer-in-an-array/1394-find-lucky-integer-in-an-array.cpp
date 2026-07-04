class Solution {
public:
    int findLucky(vector<int>& arr) {
        int maxi=-1;
        unordered_map<int,int>mpp;
        for(int i:arr){
            mpp[i]++;
        }
        for(auto it:mpp){
            if(it.first==it.second){
                maxi=max(maxi,it.first);
            }
        }
        return maxi;
    }
};