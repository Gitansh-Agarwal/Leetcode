class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int> ans;
        
        for(int start=1; start<10; start++){
            int curDigit = start+1;
            int curValue = start;
            
            if(curValue>=low && curValue<=high){
                ans.push_back(curValue);
            }
            
            for(; curDigit<10; curDigit++){
                curValue*=10;
                curValue+=curDigit;
                
                if(curValue>=low && curValue<=high){
                    ans.push_back(curValue);
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};