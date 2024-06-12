class Solution {
public:
    void swap(int &a, int &b){
        int temp=a;
        a=b;
        b=temp;
    }
    void sortColors(vector<int>& nums) {
        //Better Solution using Count Sort
        //TC=O(2*N), extra SC=O(3 extra variables).
//         int cnt0=0, cnt1=0, cnt2=0;
//         for(int i=0; i<nums.size(); i++){
//             if(nums[i]==0)
//                 cnt0++;
//             else if(nums[i]==1)
//                 cnt1++;
//             else
//                 cnt2++;
//         }
        
//         int i=0;
//         while(cnt0!=0){
//             nums[i]=0;
//             i++;
//             cnt0--;
//         }
//         while(cnt1!=0){
//             nums[i]=1;
//             i++;
//             cnt1--;
//         }
//         while(cnt2!=0){
//             nums[i]=2;
//             i++;
//             cnt2--;
//         }
        
        
        
        
        //Optimal Solution
        //TC=O(N),extra SC=(3 variables/pointers).
        int mid=0;
        int start=0, end=nums.size()-1;
        
        while(mid<=end){
            if(nums[mid]==0){
                swap(nums[mid], nums[start]);
                mid++;
                start++;
            }
            else if(nums[mid]==2){
                swap(nums[mid], nums[end]);
                end--;
            }
            else{
                mid++;
            }
        }
    }
};