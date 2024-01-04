class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            ++mp[nums[i]];
        }
        int ans = 0;
        int countDivideBy3;
        for(auto it : mp){
            if(it.second == 1)
                return -1;
            if(it.second%3 == 0){
                ans+= it.second/3;
            }
            else if(it.second%3 == 2){
                countDivideBy3 = it.second/3;
                ans+=countDivideBy3;
                it.second-=(countDivideBy3) * 3;
                ans+=it.second/2;
            }
            else{
                countDivideBy3 = (it.second/3) - 1;
                ans+=countDivideBy3;
                it.second-=(countDivideBy3)*3;
                ans+=it.second/2;
            }
        }
        return ans;
    }
};