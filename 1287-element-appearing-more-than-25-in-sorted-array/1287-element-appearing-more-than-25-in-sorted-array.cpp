class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int occ=n/4;
        
        int i=0;
        int j=0;
        while(j<n){
            if(arr[i]==arr[j]){
                int l=j-i+1;
                if(l>occ){
                    return arr[j];
                }
                j++;
            }
            else{
                i=j;
                int l=j-i+1;
                if(l>occ){
                    return arr[j];
                }
                j++;
            }
        }
        return -1;
    }
};