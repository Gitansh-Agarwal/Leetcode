class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor)
            return 1;
        bool sign=true;
        if(dividend>0 && divisor<0)
            sign=false;
        if(dividend<0 && divisor>0)
            sign=false;
        
        long n=abs(dividend);
        long d=abs(divisor);
        long quotient=0;
        
        while(n>=d){
            int cnt=0;
            //Below condition can also be written as while(n>=(d<<(cnt+1)))
            // if we don't write 1L in the below conditional statement, then error-> Char 27: runtime error: shift exponent 32 is too large for 32-bit type 'int' (solution.cpp)
            while(n>=(d*(1L<<cnt+1))){//here L->long 
                cnt++;
            }
            quotient+=(1<<cnt);
            n=n-(d<<cnt);
        }
        
        if(quotient==(1<<31) && sign){
            return INT_MAX;
        }
        if(quotient==(1<<31) && !sign){
            return INT_MIN;
        }
        
        return sign ? quotient:-quotient;
    }
};