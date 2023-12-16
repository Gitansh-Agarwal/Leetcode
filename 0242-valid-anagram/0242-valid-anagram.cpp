class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size()){
            return false;
        }
        
        int *HT = new int[26];
        for(int i=0; i<26; i++){
            HT[i] = 0;
        }
        for(int i=0; s[i]!='\0'; i++){
            HT[s[i]-97]++;
        }
        for(int i=0; t[i]!='\0'; i++){
            HT[t[i]-97]--;
        }
        
        for(int i=0; i<26; i++){
            if(HT[i] != 0){
                return false; 
            }
        }
        return true;
    }
};