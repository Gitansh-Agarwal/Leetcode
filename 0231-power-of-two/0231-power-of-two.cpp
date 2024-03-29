class Solution {
public:
    bool isPowerOfTwo(int n) {
        //Below code is giving TLE Error.
        // if(n<0)
        //     return false;
        // while(n%2 == 0){
        //     n/=2;
        // }
        // if(n == 1)
        //     return true;
        // return false;


        //OR 
        // As n==2^x => n will always be positive and we will iterate from i=0 to i=30 and
        // each time compare whether 2^i == n or not.  
//         for(int i=0; i<=30; i++){
//             int ans = pow(2, i);
            
//             if(ans == n)
//                 return true;
//         }
//         return false;

        //Using Bit Manipulation
        // if(n<0)
        //     return false;
        // int count=0;
        // while(n!=0){
        //     if(n & 1 == 1){
        //         count++;
        //     }
        //     n = n >> 1;
        // }
        // if(count == 1)
        //     return true;
        // return false;
        
        
        if(n<=0){
            return false;
        }
        int count=0;
        for(int i=0; i<32; i++){
            if((n>>i) & 1 == 1){
                count++;
            }
            if(count>1){
                return false;
            }
        }
        if(count==1){
            return true;
        }
        return false;
    }
};