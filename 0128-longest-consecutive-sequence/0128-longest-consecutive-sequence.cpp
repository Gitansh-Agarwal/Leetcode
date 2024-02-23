// #include<bits/stdc++.h>
class Solution {
public:
    //Brute Force Solution
    // bool linearSearch(vector<int> temp, int val){
    //     for(int i=0; i<temp.size(); i++){
    //         if(val == temp[i]){
    //             return 1;
    //         }
    //     }
    //     return 0;
    // }
    int longestConsecutive(vector<int>& nums) {
        //Brute Force Solution.
        //TC=O(N^3), extra SC=O(1)
        //Below code is giving TLE Error.
        // int n=nums.size();
        // int maxLength=0;
        // for(int i=0; i<n; i++){
        //     int x=nums[i];
        //     int cnt=1;
        //     while(linearSearch(nums, x+1) == true){
        //         cnt+=1;
        //         x+=1;
        //     }
        //     maxLength = max(maxLength, cnt);
        // }
        // return maxLength;
        
        
        
        
        //Better Solution
        //TC=O(NlogN)+ O(N), extra SC=O(1).
        // int maxLength=0;
        // int length=1;
        // int n=nums.size();
        // if(n == 0)
        //     return 0;
        // sort(nums.begin(), nums.end());
        // for(int i=1; i<n; i++){
        //     if(nums[i] == nums[i-1])
        //         continue;
        //     if(nums[i] - nums[i-1] == 1){
        //         length++;
        //     }
        //     else{
        //         maxLength = max(maxLength, length);
        //         length=1;
        //     }
        // }
        // maxLength = max(maxLength, length);
        // return maxLength;
        
        //OR
        // int lastSmaller= INT_MIN;
        // int n=nums.size();
        // int maxLength=0;
        // int cnt=0;
        // sort(nums.begin(), nums.end());
        // for(int i=0; i<n; i++){
        //     if(lastSmaller == nums[i] - 1){
        //         cnt++;
        //         lastSmaller= nums[i];
        //     }
        //     else if(lastSmaller != nums[i]){
        //         cnt=1;
        //         lastSmaller = nums[i];
        //     }
        //     maxLength= max(maxLength, cnt);
        // }
        // return maxLength;
        
        
        //Optimal Solution = Using Unordered Set.
        //TC=O(3*N), extra SC=O(N) assuming unordered_set uses O(1) time complexity
        unordered_set<int> st;
        int length=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }
        
        for(auto it: st){
            if(st.find(it-1) == st.end()){
                int cnt=1;
                int x=it;
                while(st.find(x+1) != st.end()){
                    cnt++;
                    x=x+1;
                }
                length = max(length, cnt);
            }
        }
        return length;
    }
};