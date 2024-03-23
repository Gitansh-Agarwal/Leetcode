class Solution {
public:
    // int binarySearch(vector<int>& arr, int target){
    //     int n=arr.size();
    //     int low=0;
    //     int high=n-1;
    //     int mid;
    //     while(low<=high){
    //         mid=(low+high)/2;
    //         if(arr[mid]==target)
    //             // return mid;
    //             break;
    //         else if(arr[mid]>target){
    //             high=mid-1;
    //         }
    //         else{
    //             low=mid+1;
    //         }
    //     }
    //     return mid;
    // }
    int search(vector<int>& nums, int target) {
        // sort(nums.begin(), nums.end());
        // return binarySearch(nums, target);
        int low=0;
        int n=nums.size();
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target)
                return mid;

            //left half is sorted
            else if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<=nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            //right half is sorted
            else{
                if(nums[mid]<=target && target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};