class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //Brute Force Solution
        //1. Generate all permutations in sorted order.
        //2. Linear Search to find the given permutation.
        //3. The permutation at the next index will be the required answer.
        
        
        //Better Solution
        // next_permutation(nums.begin(), nums.end());
        
        
        //Optimal Solution
        int index=-1;
        int n=nums.size();
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        if(index == -1){
            reverse(nums.begin(), nums.end());
        }
        else{
            for(int i=n-1; i>index; i--){
                if(nums[i] > nums[index]){
                    swap(nums[index], nums[i]);
                    break;
                }
            }
            sort(nums.begin()+index+1, nums.end());
            // reverse(nums.begin()+index+1, nums.end());
        }
    }
};