class Solution {
public:
    int minimumDeletions(string s) {
        //TC=O(N), SC=O(N).
//         int count=0;
//         stack<char> stk;
        
//         for(int i=0; i<s.size(); i++){
//             if(!stk.empty() && s[i]=='a' && stk.top()=='b'){
//                 stk.pop();
//                 count++;
//             }
//             else{
//                 stk.push(s[i]);
//             }
//         }
//         return count;
        
        
        
        //using two vectors for count.
        //TC=O(3N), SC=O(2N)
//         int n=s.size();
//         vector<int> left_b(n,0);
//         vector<int> right_a(n,0);
        
//         int countb=0;
//         for(int i=0; i<n; i++){
//             left_b[i]=countb;
//             if(s[i]=='b'){
//                 countb++;
//             }
//         }
        
//         int counta=0;
//         for(int i=n-1; i>=0; i--){
//             right_a[i]=counta;
//             if(s[i]=='a'){
//                 counta++;
//             }
//         }
        
//         int count=INT_MAX;
//         for(int i=0; i<n; i++){
//             count=min(count, left_b[i]+right_a[i]);
//         }
//         return count;
        
        //TC=O(2N), SC=O(1).
        int n=s.size();
        int counta=0;
        for(int i=0; i<n; i++){
            if(s[i]=='a'){
                counta++;
            }
        }
        int countb=0;
        int count=INT_MAX;
        
        for(int i=0; i<n; i++){
            if(s[i]=='a'){
                counta--;
            }
            count=min(count, counta+countb);
            if(s[i]=='b'){
                countb++;
            }
        }
        return count;
    }
};