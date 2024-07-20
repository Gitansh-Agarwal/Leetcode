class Solution {
public:
    int minimumLength(string s) {
        vector<int> temp(26, 0);
        int n=s.size();
        for(int i=0; i<n; i++){
            temp[s[i]-'a']++;
        }
        
        int cnt=0;
        for(int i=0; i<26; i++){
            if(temp[i]%2 ==1){
                cnt+=1;
            }
            else if(temp[i]!=0){
                cnt+=2;
            }
        }
        return cnt;
        
    }
};