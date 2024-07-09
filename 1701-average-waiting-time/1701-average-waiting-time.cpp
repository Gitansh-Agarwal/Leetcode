class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        double totalWaitTime=customers[0][1];
        int arrivalTime=customers[0][0]+customers[0][1]; 
        for(int i=1; i<n; i++){
            if(arrivalTime >= customers[i][0]){
                arrivalTime+=customers[i][1];
                totalWaitTime+=(arrivalTime-customers[i][0]);
            }
            else{
                arrivalTime=customers[i][0]+customers[i][1];
                totalWaitTime+=customers[i][1];
            }
        }
        
        return (totalWaitTime/(double)n);
        
    }
};