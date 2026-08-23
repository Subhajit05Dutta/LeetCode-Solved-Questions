class Solution {
public:
    int freq(unordered_map<int,int>&mpp){
        int total=0;
        for(auto &it:mpp){
            total+=it.second;
        }
        return total;
    }
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mpp;
        int n=fruits.size();
        int l=0,r=0;
        int cnt=0,maxcnt=0;
        while(r<n){
            mpp[fruits[r]]++;
            while(mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0){
                    mpp.erase(fruits[l]);
                }
                l++;
            }
            cnt=freq(mpp);
            maxcnt=max(cnt,maxcnt);
            r++;
        }
        return maxcnt;
    }
};