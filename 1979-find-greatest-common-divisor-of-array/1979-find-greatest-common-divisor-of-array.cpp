class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums[0];
        int m = nums[nums.size()-1];
        
        while(n>0 && m>0){
            if(n>m)
                n=n%m;
            else
                m=m%n;
        }
        if(n==0)
            return m;
        return n;
    }
};