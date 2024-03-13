class Solution {
public:
    int pivotInteger(int n) {
        int sumTotal=n*(n+1)/2;
        int sumLeft=0;
        
        for(int i=1; i<=n; i++){
            sumLeft+=i;
            int sumRight=sumTotal-sumLeft+i;
            if(sumLeft==sumRight){
                return i;
            }
        }
        return -1;
    }
};