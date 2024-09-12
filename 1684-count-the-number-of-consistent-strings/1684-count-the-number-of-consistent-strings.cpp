class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st;
        int n1 = allowed.size();
        // int n2 = words.size();
        
        for(int i=0; i<n1; i++){
            st.insert(allowed[i]);
        }
        
        int cnt=0;
        for(auto word: words){
            int temp=0;
            for(auto ch: word){
                if(st.find(ch) == st.end()){
                    temp=1;
                    break;
                }
            }
            if(temp == 0){
                cnt++;
            }
        }
        return cnt;
    }
};