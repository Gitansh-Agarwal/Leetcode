class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
//         Below method Time Complexity = O(N) and Space Complexity = O(N).
//         vector<int> prefixSum;
//         int length = arr.size();
//         int diff = arr[0];
//         int diff2;
//         int count = 1;
//         prefixSum.push_back(arr[0]);
//         for(int i=1; i<length; i++){
            
//             prefixSum.push_back(prefixSum[i-1] + arr[i]);
            
//         }
//         for(int i=1; i<length; i++){
            
//             diff2 = prefixSum[i] - prefixSum[i-1];
            
//             if(diff2 == diff){
//                 count++;
//             }
//             else{
//                 diff = diff2;
//                 count = 1;
//             }
            
//             if(count > (length/4)){
                
//                 return diff;
//             }
            
//         }
//         return diff;
        
        
        //Below Method Time Comlexity = O(N) and Space Complexity = O(1).
        
        int count = 1;
        int length = arr.size();
        int need = length/4;
        
        for(int i=1; i<length; i++){
            
            if(arr[i] == arr[i-1]){
                count++;
            }
            else{
                
                if(count > need){
                    
                    return arr[i-1];
                }
                count = 1;
            }
        }
        return arr[length -1];
            
   }
};