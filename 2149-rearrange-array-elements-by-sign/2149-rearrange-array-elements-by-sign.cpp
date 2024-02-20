class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        //Brute Force Solution 
        //TC=O(2*N) , extra SC = O(N).
        // vector<int> positive;
        // vector<int> negative;
        // int n=nums.size();
        // for(int i=0; i<n; i++){
        //     if(nums[i] > 0 ){
        //         positive.push_back(nums[i]);
        //     }
        //     else{
        //         negative.push_back(nums[i]);
        //     }
        // }
        // // int j=0;
        // // int k=0;
        // // for(int i=0; i<nums.size(); i++){
        // //     if(i%2 == 0){
        // //         nums[i] = positive[j++];
        // //     }
        // //     else{
        // //         nums[i] = negative[k++];
        // //     }
        // // }

        // // OR optimized for loop
        // for(int i=0; i<n/2; i++){
        //     nums[2*i] = positive[i];
        //     nums[2*i+1] = negative[i];
        // }


        // return nums;


        //Optimal Solution 
        //TC=O(N), extra SC=O(N)
        int n=nums.size();
        vector<int> ans(n, 0);
        int pos = 0; 
        int neg = 1;
        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                ans[pos] = nums[i];
                pos+=2;
            }
            else{
                ans[neg] = nums[i];
                neg+=2;
            }
        }
        return ans;
    }
};