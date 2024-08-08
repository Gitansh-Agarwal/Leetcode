class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int num=0;
        int temp=0;
        int i=0;
        int sign=1;//1 for positive, 0 for negative.
        while(s[i]==' '){
            i++;
        }
        while(i<n){
            if(s[i]=='-' && temp==0){
                sign=0;
                temp=1;
            }
            else if(s[i]=='+' && temp==0){
                temp=1;
            }
            else if(s[i]>=48 && s[i]<=57){
                temp=1;
               if(sign==1){
                    if(num > (INT_MAX/10)  || (num == (INT_MAX/10) && (s[i]-'0')>7)){
                        num=INT_MAX;
                        return num;
                    }
               }
               else{
                    if((num > (INT_MAX/10))  || (num == (INT_MAX/10) && (s[i]-'0')>=8)){
                        num=INT_MIN;
                        return num;
                    }
                }  
                num = num*10 + (s[i]-'0');
            }
            else{//any other character.
                break;
            }
            i++;
        }
        if(sign==0){
            num*=-1;
        }
        return num;
    }
};