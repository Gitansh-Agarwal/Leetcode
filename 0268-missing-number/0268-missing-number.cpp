class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //Brute Force Solution
        //TC=O(N*N), extra SC=O(1).
        // for(int i=0; i<=nums.size(); i++){
        //     bool flag=0;
        //     for(int j=0; j<nums.size(); j++){
        //         if(nums[j] == i){
        //             flag=1;
        //             break;
        //         }
        //     }
        //     if(flag==0)
        //         return i;
        // }
        // return 0;


        //Better Solution
        //TC = O(2*N) , extra SC =O(N). 
        // vector<int> freq(nums.size()+1, 0);
        // for(auto it : nums){
        //     ++freq[it];
        // }
        // int i;
        // for( i=0; i< nums.size()+1; i++){
        //     if(freq[i] == 0)
        //         break;
        // }
        // return i;


        //Optimal Solution
        //Method 1
        // TC=O(N), extra SC=O(1).
        // int n= nums.size();
        // int sum1=n*(n+1)/2;
        // int sum2=0;
        // for(int i=0; i<n; i++){
        //     sum2+=nums[i];
        // }
        // return sum1-sum2;

        
        //Method 2
        //TC= O(2*N), extra SC=O(1)
        // int xor1=0;
        // int xor2=0;
        // int n=nums.size();
        // for(int i=1; i<=n; i++){
        //     xor1= xor1^i;
        // } 
        // for(int i=0; i<n; i++){
        //     xor2=xor2^nums[i];
        // }
        // return xor1^xor2;


        //Method 3
        //TC=O(N), extra SC=O(1).
        int n= nums.size();
        int xor1=0;
        int xor2=0;
        for(int i=0; i<n; i++){
            xor2=xor2^nums[i];
            xor1=xor1^(i+1);
        }
        return xor1^xor2;
    }
};