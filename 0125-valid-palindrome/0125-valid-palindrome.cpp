class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        string tempReverse;
        for(int i=0; s[i]!='\0'; i++){
            if((s[i]>=48 && s[i]<=57) || (s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)){
                if(s[i]>=65 && s[i]<=90){
                    temp.push_back((char)(s[i]+32));
                }
                else{
                    temp.push_back(s[i]);
                }
            }
        }
        tempReverse = temp;
        reverse(tempReverse.begin(), tempReverse.end());
        if(temp == tempReverse)
            return true;
        return false;
    }
};