class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        
        vector<int> prefixSum;
        int length = arr.size();
        int diff = arr[0];
        int diff2;
        int count = 1;
        prefixSum.push_back(arr[0]);
        for(int i=1; i<length; i++){
            
            prefixSum.push_back(prefixSum[i-1] + arr[i]);
            
        }
        for(int i=1; i<length; i++){
            
            diff2 = prefixSum[i] - prefixSum[i-1];
            
            if(diff2 == diff){
                count++;
            }
            else{
                diff = diff2;
                count = 1;
            }
            
            if(count > (length/4)){
                
                return diff;
            }
            
        }
        return diff;
    }
};