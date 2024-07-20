class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //Brute Force Solution = Merging two sorted arrays and then finding out the median of the resultant. 
        //TC=O(m+n).
        //SC=O(1).
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
        //
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
        int ind1=n/2;
        int ind2=ind1-1;
        int ind1El=-1, ind2El=-1;
        int cnt=0;
        int i=0, j=0;
        while(i<n1 && j<n2){
            if(nums1[i] < nums2[j]){
                if(cnt == ind1) ind1El=nums1[i];
                if(cnt == ind2) ind2El=nums1[i];
                i++;
            }
            else{
                if(cnt == ind1) ind1El=nums2[j];
                if(cnt == ind2) ind2El=nums2[j];
                j++;
            }
            cnt++;
        }
        while(i<n1){
            if(cnt == ind1) ind1El=nums1[i];
            if(cnt == ind2) ind2El=nums1[i];
            i++;
            cnt++;
        }
        while(j<n2){
            if(cnt == ind1) ind1El=nums2[j];
            if(cnt == ind2) ind2El=nums2[j];
            j++;
            cnt++;
        }
        
        if(n%2 == 1){
            return ind1El;
        }
        else{
            return (double)(ind1El+ind2El)/2.0;
        }
    }
};