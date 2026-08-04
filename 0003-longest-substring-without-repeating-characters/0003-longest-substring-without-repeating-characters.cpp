class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int low=0,high=0;
        int maxcnt=0;
        unordered_set<char>st;
        while(high<n){
            if(st.find(s[high])==st.end()){
                st.insert(s[high]);
                
            }
            else{
                char ch=s[high];
                while(ch!=s[low]){
                    st.erase(s[low]);
                    low++;
                }
                st.erase(s[low]);
                low++;
                st.insert(s[high]);
            }
            maxcnt=max(maxcnt,(high-low+1));
            high++;
        }
        return maxcnt;
    }
};
