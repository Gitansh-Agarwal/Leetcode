class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //Brute Force Solution = Merging two sorted arrays and then finding out the median of the resultant. 
        //TC=O(m+n).
        //SC=O(1).
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> mergedVector(n1+n2);
        
        int i=0, j=0;
        int k=0;
        while(i<n1 && j<n2){
            if(nums1[i] < nums2[j]){
                mergedVector[k++]=nums1[i++];
            }
            else{
                mergedVector[k++]=nums2[j++];
            }
        }
        while(i<n1){
            mergedVector[k++]=nums1[i++];
        }
        while(j<n2){
            mergedVector[k++]=nums2[j++];
        }
        
        int n=n1+n2;
        if(n%2==1){
            return mergedVector[n/2];
        }
        else{
            return (double)(mergedVector[n/2]+mergedVector[n/2-1])/2.0;
        }
    }
};