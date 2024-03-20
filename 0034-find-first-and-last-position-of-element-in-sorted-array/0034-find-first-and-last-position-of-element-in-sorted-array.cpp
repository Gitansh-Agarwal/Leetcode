class Solution {
public:
    int startPos(vector<int>&arr, int target){
        int ans=-1;
        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==target){
                ans=mid;
                high=mid-1;
            }
            else if(arr[mid]>target){
                // low=mid+1;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int endPos(vector<int>&arr, int target){
        int ans=-1;
        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==target){
                ans=mid;
                low=mid+1;
            }
            else if(arr[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        // vector<int> ans;
        // ans.push_back(startPos(nums, target));
        // ans.push_back(endPos(nums, target));
        // return ans;
        
        //OR
        int first=startPos(nums, target);
        if(first==-1)  return {-1, -1};
        int last=endPos(nums, target);
        return {first, last};
    }
};