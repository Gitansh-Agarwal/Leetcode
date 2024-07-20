class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //Brute Force Solution = Merging two sorted arrays and then finding out the median of the resultant. 
        //TC=O(m+n).
        //SC=O(m+n).
//         int n1=nums1.size();
//         int n2=nums2.size();
//         vector<int> mergedVector(n1+n2);
        
//         int i=0, j=0;
//         int k=0;
//         while(i<n1 && j<n2){
//             if(nums1[i] < nums2[j]){
//                 mergedVector[k++]=nums1[i++];
//             }
//             else{
//                 mergedVector[k++]=nums2[j++];
//             }
//         }
//         while(i<n1){
//             mergedVector[k++]=nums1[i++];
//         }
//         while(j<n2){
//             mergedVector[k++]=nums2[j++];
//         }
        
//         int n=n1+n2;
//         if(n%2==1){
//             return mergedVector[n/2];
//         }
//         else{
//             return (double)(mergedVector[n/2]+mergedVector[n/2-1])/2.0;
//         }
        
        
        
        
        
        //Better Solution
        // TC=O(m+n).
        //SC=O(1).
//         int n1=nums1.size();
//         int n2=nums2.size();
//         int n=n1+n2;
//         int ind1=n/2;
//         int ind2=ind1-1;
//         int ind1El=-1, ind2El=-1;
//         int cnt=0;
//         int i=0, j=0;
//         while(i<n1 && j<n2){
//             if(nums1[i] < nums2[j]){
//                 if(cnt == ind1) ind1El=nums1[i];
//                 if(cnt == ind2) ind2El=nums1[i];
//                 i++;
//             }
//             else{
//                 if(cnt == ind1) ind1El=nums2[j];
//                 if(cnt == ind2) ind2El=nums2[j];
//                 j++;
//             }
//             cnt++;
//         }
//         while(i<n1){
//             if(cnt == ind1) ind1El=nums1[i];
//             if(cnt == ind2) ind2El=nums1[i];
//             i++;
//             cnt++;
//         }
//         while(j<n2){
//             if(cnt == ind1) ind1El=nums2[j];
//             if(cnt == ind2) ind2El=nums2[j];
//             j++;
//             cnt++;
//         }
        
//         if(n%2 == 1){
//             return ind1El;
//         }
//         else{
//             return (double)(ind1El+ind2El)/2.0;
//         }
        
        
        
        
        //Optimal Solution = Using Binary Seach on smaller sized vector to identify the patition point(mid1).
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);
        int left = (n1 + n2 + 1)/2; 
        int n=n1+n2;
        int low=0, high=n1;
        while(low <= high){
            int mid1 = (low+high)/2;
            int mid2 = left-mid1;
            int l1=INT_MIN, l2=INT_MIN;
            int r1=INT_MAX, r2=INT_MAX;
            if(mid1 < n1) r1=nums1[mid1];
            if(mid2 < n2) r2=nums2[mid2];
            if(mid1-1 >= 0) l1=nums1[mid1-1];
            if(mid2-1 >= 0) l2=nums2[mid2-1];
            
            if(l1<=r2 && l2<=r1){//Valid Configuration
                if(n%2 == 1){
                    return max(l1, l2);
                }
                else{
                    return (double)(max(l1,l2) + min(r1, r2))/2.0;
                }
            }
            else if(l1 > r2){
                high=mid1-1;
            }
            else if(l2 > r1){
                low=mid1+1;
            }
        }
        return 0;
    }
};