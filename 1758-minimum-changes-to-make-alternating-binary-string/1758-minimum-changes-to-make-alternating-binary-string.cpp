class Solution {
public:
    int minOperations(string s) {
        
        //we can have alternating binary strings that starts from either "10101010"  OR starts from "01010101", so we can check the given string with alternating string starting with '1' and count the operations to be performed to make given string alternating and also check the given string with alternating string starting with '0' and count the number of operations to be performed to make the given string alternating and whichever comparison requires minimum number of operations to make given string alternating, we return that value.
        
        //string starting with 0
        int expect = 0;
        int ans1 = 0;
        
        for(auto i : s){
            ans1+= expect != (i-'0');
            
            expect^=1;
        }
        
        //string starting with 1
        expect = 1;
        int ans2 = 0;
        for(auto i : s){
            ans2+= expect != (i-'0');
            
            expect^=1;
            
        }
        
        return min(ans1,ans2);
    }
};