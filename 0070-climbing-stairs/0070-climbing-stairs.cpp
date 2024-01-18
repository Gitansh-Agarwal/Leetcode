class Solution {
public:
    int climbStairs(int n) {
        if(n <= 3)
            return n;
        int first = 2; 
        int second  = 3;
        int third;
        for(int i=4 ; i<=n; i++){
            third = first+second;
            first = second;
            second = third;
        }
        return third;
    }
};