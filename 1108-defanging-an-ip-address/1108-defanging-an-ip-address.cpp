class Solution {
public:
    string defangIPaddr(string address) {
        string ip="";
        int i=0;
        while(i<address.size()){
            if(address[i]=='.'){
                ip+="[.]";  
            }
            else{
                ip+=address[i];
            }
            i++;
        }
        return ip;
    }
};