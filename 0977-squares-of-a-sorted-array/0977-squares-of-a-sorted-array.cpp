class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //BRute Force Approach
        //TC=O(NlogN) , extra SC=O(1).
        // int n=nums.size();
        // for(int i=0; i<n; i++){
        //     nums[i]*= nums[i];
        // }
        // sort(nums.begin(), nums.end());
        // return nums;
        
        
        //Optimal Approach
        //TC=O(N), SC=O(N){for returning the answer.}
        int n=nums.size();
        vector<int> res(n);
        int i=0, j=n-1;
        int k=n-1;
        while(i<=j){
            int n1=nums[i]*nums[i];
            int n2=nums[j]*nums[j];
            if(n2 > n1){
                res[k--] = n2;
                j--;
            }
            else{
                res[k--] = n1;
                i++;
            }
        }
        return res;
    }
};