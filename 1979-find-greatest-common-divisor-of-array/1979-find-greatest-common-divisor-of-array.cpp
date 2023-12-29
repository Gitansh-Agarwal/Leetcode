class Solution {
public:
    int findGCD(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int n = nums[0];
        // int m = nums[nums.size()-1];
        
        // OR
        
        int m = INT_MIN;
        int n = INT_MAX;
        int length = nums.size();
        for(int i=0; i<length; i++){
            if(nums[i] < n)
                n = nums[i];
            if(nums[i] > m)
                m = nums[i];
        }
        //m is the maximum value in the vector.
        //n is the minimum value in the vector.
        //Using Euclidean Algorithm
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