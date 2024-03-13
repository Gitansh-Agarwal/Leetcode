class Solution {
public:
    string largestOddNumber(string num) {
        int index=-1;
        int length=num.size();
        for(int i=0; i<length; i++){
            char ch=num[length-1-i];
            if((ch-'0')%2 == 1){
                index=length-1-i;
                break;
            }
        } 
        string ans="";
        if(index != -1){
            for(int i=0; i<=index; i++){
                ans+=num[i];
            }
        }
        
        return ans;
    }
};