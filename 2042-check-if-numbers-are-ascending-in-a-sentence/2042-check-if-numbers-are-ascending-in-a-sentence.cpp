class Solution {
public:
    bool areNumbersAscending(string s) {
        int temp=0;
        int prevNum=INT_MIN;
        int num;
        if(s[0]>=48 && s[0]<=57){
            temp=1;
            num=s[0]-'0';
            // prevNum=num;
        }
        for(int i=1; i<s.size(); i++){
            if(s[i]>=48 && s[i]<=57 && s[i-1]>=48 && s[i-1]<=57){
                temp=1;
                num=num*10+ (s[i]-'0');
            }
            else if(s[i]>=48 && s[i]<=57){
                temp=1;
                num=s[i]-'0';
            }
            else{// if the current char is a space or it is an alphabet.
                if(temp==1){
                    if(num <=prevNum){
                        return false;
                    }
                    prevNum=num;
                    num=0;
                    temp=0;
                }
                
            }
        }
        if(temp==1 && num <=prevNum){
            return false;
        }
        return true;
    }
};