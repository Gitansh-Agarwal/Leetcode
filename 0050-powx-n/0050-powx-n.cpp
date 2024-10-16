class Solution {
public:
    double calcPow(double x, int n, double ans, long long nCopy){
        
        if(nCopy == 0){
            return 1;
        }
        
        if(nCopy%2 == 0){
            return calcPow(x*x, n, ans, nCopy/2);
        }
        else{
            return x*calcPow(x, n, ans, nCopy-1);
        }
    }
    double myPow(double x, int n, double ans = 1.0) {
        //TC = O(log2(n)). as the nCopy is divided into half each time when its even and when its odd its reduced by 1 to make it even.
        //SC = O(1).
//         long long nCopy = n;
//         if(nCopy<0)    nCopy*=-1;
        
//         //Binary Exponentiation.
//         while(nCopy > 0){
//             if(nCopy%2){
//                 ans = ans*x;
//                 nCopy-=1;
//             }
//             else{
//                 x = x*x;
//                 nCopy/=2;
//             }
//         }
        
        
//         if(n<0){
//             return 1.0/ans;
//         }
//         return ans;
        
        
//         static long long nCopy=abs(n);
//         if(nCopy == 0){
//             return 1;
//         }
        
        
//         if(nCopy%2 == 0){
//             return myPow(x*x, n, ans, nCopy);
//         }
//         else{
//             return 
//         }
//         return 0;
        
        
        
        long long nCopy = abs(n);
        ans = calcPow(x, n, ans, nCopy);
        
        if(n<0){
            return 1.0/ans;
        }
        return ans;
        
    }
};