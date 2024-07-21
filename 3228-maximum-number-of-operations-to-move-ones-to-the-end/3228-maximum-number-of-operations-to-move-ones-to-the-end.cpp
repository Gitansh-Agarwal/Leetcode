class Solution {
public:
    int maxOperations(string s) {
        //Complex Version
        // int n=s.size();
        // int startIndex=-1;
        // //traversing from the end till we find a '0' as after that zero the "1's" will start to have an impact while shifting.
        // for(int i=n-1; i>=0; i--){
        //     if(s[i]=='0'){
        //         startIndex=i;
        //         break;
        //     }
        // }
        // int ans=0;
        // int impact=1;
        // for(int i=startIndex; i>=0; i--){
        //     if(s[i]=='0')   continue;
        //     int cnt=1;
        //     int j;
        //     for(j=i-1; j>=0; j--){
        //         if(s[j]=='0')   break;
        //         cnt++;
        //     }
        //     ans+=cnt*impact;
        //     impact++;
        //     i=j+1;
        // }
        // return ans;
        
        
        
        
        //Simplified Version.
        reverse(s.begin(),s.end());
        
        int n=s.size();
        int startIndex=n;
        
        for(int i=0; i<n; i++){
            if(s[i]=='0'){
                startIndex=i;
                break;
            }
        }
        
        int ans=0;
        int impact=1;
        for(int i=startIndex; i<n; i++){
            if(s[i]=='0')   continue;
            int cnt=1;
            int j;
            for(j=i+1; j<n; j++){
                if(s[j]=='0')   break;
                cnt++;
            }
            ans+=cnt*impact;
            impact++;
            i=j-1;
        }
        return ans;
    }
};