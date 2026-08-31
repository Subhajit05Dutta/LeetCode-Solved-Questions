class Solution {
public:
    string reformatNumber(string number) {
        string ans="";
        for(int i=0;i<number.size();i++){
            if(isdigit(number[i])){
                ans+=number[i];
            }
            else
            continue;
        }
        if(ans.size()==2 || ans.size()==3){
            return ans;
        }
        int len=ans.size();
        int i=0;
        string temp;
        while(len>0){
            if(len>4){
               temp+=ans.substr(i,i+3);
               ans.erase(i,3);
               len-=3;
               temp+="-"; 
            }
            else if(len==3){
                temp+=ans.substr(i,i+3);
                ans.erase(i,3);
                len-=3;
                temp+="-";
            }
            else if(len==2){
                temp+=ans.substr(i,i+2);
                ans.erase(i,2);
                len-=2;
                temp+="-";
            }
            else if(len==4){
                temp+=ans.substr(i,i+2);
                ans.erase(i,2);
                len-=2;
                temp+="-";
            }
        }
        temp.pop_back();
        return temp;
    }
};