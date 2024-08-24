class Solution {
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    string b;
    private:
        //performing BackTracking from endWord to beginWord to find out the shortest transformational sequence.
        void dfs(string word, vector<string>& seq){
            seq.push_back(word);
            int steps=mpp[word];
            int sz=word.size();
            
            if(word == b){
                //reversing the sequence as it is from endWord to beginWord so as to make it in required form.
                reverse(seq.begin(), seq.end());
                ans.push_back(seq);
                //reversing the sequence again so that data passed into another call is as it is and is not tempered otherwise if we pass as it is and then we pop_back last element of the sequence, we actually have popped the wrong element{as we have reversed the string}, so that's why we again need to reverse it back.
                reverse(seq.begin(), seq.end());
                return;
            }
            for(int i=0; i<sz; i++){
                char original = word[i];
                
                for(char ch='a'; ch<='z'; ch++){
                    word[i]=ch;
                    
                    if(mpp.find(word) != mpp.end()
                      && mpp[word]+1 == steps){
                        
                        dfs(word, seq);
                        seq.pop_back();
                    }
                }
                word[i]=original;
            }
            
        }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //This method is giving MLE Error as the queue size can be very big depending on the input which can lead to Memory Limit Exceeded Error.
//         unordered_set<string> st(wordList.begin(), wordList.end());
//         queue<vector<string>> q;
//         q.push({beginWord});
//         vector<string> usedOnLevel;
//         usedOnLevel.push_back(beginWord);
//         int level=0;
//         vector<vector<string>> ans;
//         while(!q.empty()){
//             vector<string> vec=q.front();
//             q.pop();
            
//             //erase all the words that has been used at the previous levels to transform.
//             if(vec.size() > level){
//                 level++;
//                 for(auto it: usedOnLevel){
//                     st.erase(it);
//                 }
//                 usedOnLevel.clear();
//             }
            
//             string word=vec.back();
//             //store the answers
//             if(word==endWord){
//                 //the first sequence where we reached to word endWord.
//                 if(ans.size()==0){
//                     ans.push_back(vec);
//                 }
//                 else if(ans[0].size()==vec.size()){
//                     ans.push_back(vec);
//                 }
//                 else if(ans[0].size()<vec.size()){
//                     break;
//                 }
//             }
            
//             //wordlength*26*queue size{which depends on the input}.
//             for(int i=0; i<word.size(); i++){
//                 char originalChar=word[i];
//                 for(char ch='a'; ch<='z'; ch++){
//                     word[i]=ch;
                    
//                     if(st.find(word) != st.end()){
//                         vec.push_back(word);
//                         q.push(vec);
                        
//                         //mark as visited on the Level.
//                         usedOnLevel.push_back(word);
//                         vec.pop_back();
//                     }
//                 }
//                 word[i]=originalChar;
//             }
//         }
//         return ans;
        
        
        
        
        
        
        //Approach = CP.
        //Step-1-  We will find out the shortest sequence length and store level of every string.
        //Step-2-  Backtrack in the map from (end -> begin) to get the answer.
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        b=beginWord;
        q.push(beginWord);
        mpp[beginWord]=1;
        int sizee=beginWord.size();
        st.erase(beginWord);
        while(!q.empty()){
            string word=q.front();
            int steps=mpp[word];
            q.pop();
            
            if(word==endWord)   break;
            for(int i=0; i<sizee; i++){
                char original=word[i];
                
                for(char ch='a'; ch<='z'; ch++){
                    word[i]=ch;
                    
                    if(st.find(word) != st.end()){
                        q.push(word);
                        st.erase(word);
                        mpp[word]=steps+1;
                    }
                }
                word[i]=original;
            }
        }
        
        if(mpp.find(endWord) !=mpp.end()){
            vector<string> seq;
            // seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};