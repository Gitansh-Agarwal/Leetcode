class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt=0;
        int n=s.size();
        for(auto it: s){
            if(it == '1')
                cnt++;
        }
        s[n-1] = '1';
        cnt--;
        int i=0; 
        for(int i=0; i<n-1; i++){
            if(cnt){
                s[i] = '1';
                cnt--;
            }
            else if(cnt == 0 && s[i]== '1'){
                 s[i]='0';
            }
            
        }
        return s;
    }
};