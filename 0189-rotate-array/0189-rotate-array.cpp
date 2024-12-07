class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        k=k%n;
        if(k==0)
            return;
        vector<int> temp(k);
        
        int j=n-k;
        for(int i=0; i<k; i++){
            temp[i] = nums[j++];
        }
        
        j=n-k-1;
        for(int i=n-1; j>=0; i--, j--){
            nums[i] = nums[j];
        }
        for(int i=0; i<k; i++){
            nums[i] = temp[i];
        }
        
    }
};