class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=m-1;
        int k;
        for(int i=0; i<n; i++){
            k=j;
            while(k>=0 && nums1[k] > nums2[i]){
                nums1[k+1]=nums1[k];
                k--;
            }
            nums1[k+1]=nums2[i];
            j++;
        }
    }
};