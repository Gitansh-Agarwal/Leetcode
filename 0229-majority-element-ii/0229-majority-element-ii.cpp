class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //Better Solution
        //TC=O(N), extra SC=O(N).
        // unordered_map<int, int> mpp;
        // vector<int> ans;
        // int n=nums.size();
        // int req=n/3+1;
        // for(auto it: nums){
        //     if(mpp[it] == req-1)
        //         ans.push_back(it);
        //     mpp[it]++;
        // }
        // // for(auto it: mpp){
        // //     if(it.second > (nums.size()/3))
        // //         ans.push_back(it.first);
        // // }
        // return ans;
        
        
        //Optimal Solution
        //TC=O(2*N), extra SC=O(1).
        int cnt1=0, cnt2=0;
        int ele1=INT_MIN, ele2=INT_MIN;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(cnt1==0 && nums[i]!=ele2){
                cnt1=1;
                ele1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=ele1){
                cnt2=1;
                ele2=nums[i];
            }
            else if(ele1 == nums[i])
                cnt1++;
            else if(ele2 == nums[i])
                cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0, cnt2=0;
        for(int i=0; i<n; i++){
            if(nums[i] == ele1)
                cnt1++;
            else if(nums[i] == ele2)
                cnt2++;
        }
        int req= (n/3);
        vector<int> ans;
        if(cnt1> req)
            ans.push_back(ele1);
        if(cnt2> req)
            ans.push_back(ele2);
        return ans;
            
            
    }
};