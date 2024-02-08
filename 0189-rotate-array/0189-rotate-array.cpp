class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[(i+k)%nums.size()] = nums[i];
        }
        int i=0;
        for(auto it:mp){
            nums[i] = it.second;
            i++;
        }
        
    }
};