class Solution {
public:
    int countDigits(int num) {
        int count =0; 
        int digit;
        int temp = num;
        while(temp!=0){
            digit = temp%10;
            if(num%digit ==0)
                count++;
            temp/=10;
        }
        return count;
    }
};