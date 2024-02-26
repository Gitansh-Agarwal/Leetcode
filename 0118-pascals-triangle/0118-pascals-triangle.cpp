class Solution {
public:
    //any value in the pascal's triangle can be computed using (n-1)C(r-1).
    // here n is row and r is column.
    //finding the ncr value using O(r) time.
    //TC=O(r), extra SC=O(1).
    int nCr(int n, int r){
        long long res=1;
        for(int i=0; i<r; i++){
            res = res*(n-i);
            res = res/(i+1);
        }
        return res;
    }
    //printing nth row of the pascal's triangle.
    //TC=O(N*r), SC=O(N) , extra SC=O(1).
    vector<int> generateRow1(int n){
        vector<int> temp;
        for(int col=1; col<=n; col++){
            temp.push_back(nCr(n-1, col-1));
        }
        return temp;
    }
    // or 
    //TC=O(N){elements to be printed are equal to the row number}, SC=O(N){for storing the                 result},extra SC=O(1)
    vector<int> generateRow2(int row){
        vector<int> temp;
        temp.push_back(1);
        long long res=1;
        for(int col=1; col<row; col++){
            res=res*(row-col);
            res=res/col;
            temp.push_back(res);
        }
        return temp;
    }
    
    vector<vector<int>> generate(int numRows) {
        //Brute Force Solution
        //TC=O(N*N*r) = O(N^3), SC=O(N^2), extra SC=O(1).
        // vector<vector<int>> ans;
        // for(int row=1; row<=numRows; row++){
        //     vector<int> temp;
        //     for(int col=1; col<=row; col++){
        //         temp.push_back(nCr(row-1, col-1));
        //     }
        //     ans.push_back(temp);
        // }
        // return ans;
        
        
        //Optimal Solution
        //TC=O(N^2), SC=O(N^2), extra SC=O(1).
        vector<vector<int>> ans;
        for(int row=1; row<=numRows; row++){
            vector<int> temp = generateRow2(row);
            ans.push_back(temp);
        }
        return ans;
    }
};