class Solution {
public:
    string frequencySort(string s) {
        
        map<char, int> mp;
        for(auto it:s){
            mp[it]++;
        }
        
        priority_queue<pair<int, char>> pq;
        for(auto it:mp){
            pq.push({it.second, it.first});
        }
        
        string ans = "";
        while(!pq.empty()){
            int count;
            char ch;
            
            // tie(count, ch) = pq.top();
            count=pq.top().first;
            ch=pq.top().second;
            pq.pop();
            
            while(count--){
                ans+=ch;
            }
        }
        
        return ans;
    }
};