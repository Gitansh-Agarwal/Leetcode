class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mpp;
        mpp['I']=1;
        mpp['V']=5;
        mpp['X']=10;
        mpp['L']=50;
        mpp['C']=100;
        mpp['D']=500;
        mpp['M']=1000;
        int n=s.size();
        int eqNum=0;
        int i;
        for(i=0; i<n-1; i++){
            if(s[i] == 'I' && (s[i+1] == 'V' ||  s[i+1]=='X')){
                eqNum+= mpp[s[i+1]]-mpp[s[i]];
                i=i+1;
            }
            else if(s[i] == 'X' && (s[i+1] == 'L' ||  s[i+1]=='C')){
                eqNum+= mpp[s[i+1]]-mpp[s[i]];
                i=i+1;
            }
            else if(s[i] == 'C' && (s[i+1] == 'D' ||  s[i+1]=='M')){
                eqNum+= mpp[s[i+1]]-mpp[s[i]];
                i=i+1;
            }
            else {
                eqNum+= mpp[s[i]];
            }
        }
        // for last character
        i==n-1? (eqNum+=mpp[s[i]]):eqNum;// or i==n-1? (eqNum+=mpp[s[i]]) : -1; 
        return eqNum;
    }
};