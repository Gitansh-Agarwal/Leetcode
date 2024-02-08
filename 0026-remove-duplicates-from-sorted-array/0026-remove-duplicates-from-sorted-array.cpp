class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int temp = nums[0];
        int n = nums.size();
        for(int i=1; i<nums.size(); ){
            if(nums[i] == temp){
                nums.erase(nums.begin()+i);
            }
            else{
                temp = nums[i];
                i++;
            }
        }
        return nums.size();
    }
};