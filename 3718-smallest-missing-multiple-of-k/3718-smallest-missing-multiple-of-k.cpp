class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st;
        for(int i:nums){
            st.insert(i);
        }
        int ans=k;
        int n=nums.size();
        int i=1;
        while(true){
            if(st.find(k*i)==st.end()){
                break;
            }
            else if(st.find(k*i)!=st.end()){
                ans=k*i;
                i++;
            }
        }
        return k*i;
    }
};