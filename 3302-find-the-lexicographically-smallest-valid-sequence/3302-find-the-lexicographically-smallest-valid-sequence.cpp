class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n= word1.size();
        int m=word2.size();

        // right[i] = max length of word2's suffix that can be formed
        // using word1[i+1...n-1]

        int r=m-1;
        int c=0;
        vector<int>right(n);
        for(int i=n-1;i>=0;i--){
            right[i]=c;
            if(r>=0 && word1[i]==word2[r]){
                r--;
                c++;
            }
        }
        vector<int>ans;
        bool change=false;
        int j=0; // pointer for word2
        for(int i=0;i<n &&j<m;i++){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(!change && right[i]>=m-1-j){
                // Spend our one allowed substitution here
                ans.push_back(i);
                j++;
                change=true;
            }
        }
        if(j==m){
            return ans;
        }
        return {};
    }
};