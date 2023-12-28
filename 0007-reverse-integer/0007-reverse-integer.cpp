class Solution {
public:
    int reverse(int x) {
        
        int max = 2147483647;//INT32_MAX.
        int min = -2147483648;//INT32_MIN.
        int digit;
        int rev = 0;
        while(x!=0){
            
            digit = x % 10;
            x/=10;
            
            if((rev > max/10) or (rev == max/10  && digit > max%10))
                return 0;
            if((rev < min/10) or (rev == min/10 && digit < min%10))
                return 0;
            rev = rev*10 + digit;
        }
        
        return rev;
    }
};