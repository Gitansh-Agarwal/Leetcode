class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int minTime = 0;
        int prev = 0;
        for(int i=1; colors[i]!='\0'; i++){
            if(colors[i]==colors[prev]){
                if(neededTime[prev]<neededTime[i]){
                    minTime+=neededTime[prev];
                    prev=i;
                }
                else{
                    minTime+=neededTime[i];
                }
                
            }
            else{
                prev=i;
            }
        }
        return minTime;
    }
};