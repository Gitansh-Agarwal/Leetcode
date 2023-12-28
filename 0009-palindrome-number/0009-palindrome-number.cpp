class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int rev = 0;
        int n=x;
        int digit;
        int max = 2147483647;//INT32_MAX.
        while(n!=0){
            digit = n%10;
            n/=10;
            
            if((rev > max/10) or (rev == max/10 && digit > max%10))
                return false;
                
              
            rev = rev*10 + digit;
        }
        
        if(rev == x){
            return true;
        }
        else{
            return false;
        }
    }
};