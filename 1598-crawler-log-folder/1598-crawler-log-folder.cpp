class Solution {
public:
    int minOperations(vector<string>& logs) {
        int minOp=0;
        int n=logs.size();
        for(int i=0; i<n; i++){
            //if the given string is of the form `../`
            if(logs[i]=="../"){
                if(minOp!=0){
                    minOp--;
                }
            }
            //if the string is of the form `x/`
            else if(logs[i]!="./"){
                minOp++;
            }
            
        }
        return minOp;
    }
};