class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size()){
            return false;
        }
//         using Hash Table
        
//         int *HT = new int[26];
//         for(int i=0; i<26; i++){
//             HT[i] = 0;
//         }
//         for(int i=0; s[i]!='\0'; i++){
//             HT[s[i]-97]++;
//         }
//         for(int i=0; t[i]!='\0'; i++){
//             HT[t[i]-97]--;
//         }
        
//         for(int i=0; i<26; i++){
//             if(HT[i] != 0){
//                 return false; 
//             }
//         }
//         return true;
        
        //Without using Hash Table(not allocating memory dynamically) and using for each loop.
        
//         vector<int> vec(26,0);
        
//         for(auto i : s){
//             vec[i-'a']++;
//         }
//         for(auto i : t){
//             vec[i-'a']--;
//         }
//         for(int i=0; i<26; i++){
//             if(vec[i]!=0){
//                 return false;
//             }
//         }
//         return true;
        
        
        //Using Hashmap.
        map<char, int> mpp;
        for(auto it: s){
            mpp[it]++;
        }
        for(auto it: t){
            mpp[it]--;
        }
        for(auto it:mpp){
            if(it.second!=0){
                return false;
            }
        }
        return true;
    }
};