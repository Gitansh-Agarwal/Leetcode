class Solution {
public:
    int firstUniqChar(string s) {
        
        //Ist Method
//         vector<pair<int,int>> temp(26, {0,0});
        
//         for(int i=0; i<s.size(); i++){
//             temp[s[i]-'a'].first++;
//             if(temp[s[i]-'a'].first==1)
//                 temp[s[i]-'a'].second = i;
//         }
//         int index=INT_MAX;
//         for(int i=0; i<26; i++){
//             if(temp[i].first == 1 && temp[i].second < index)
//                 index = temp[i].second;
//         }
//         if(index != INT_MAX)
//             return index;
//         return -1;
        
        
        //IInd Method
        vector<int> temp(26, 0);
        for(auto it:s){
            temp[it - 'a']++;
        }
        for(int i=0; i<s.size(); i++){
            if(temp[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};