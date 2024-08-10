class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int length=s.size();
        string word="";
        for(int i=0; i<length; i++){
            
            if(s[i] == ' '){
                if(word==""){
                    continue;
                }
                else{
                    st.push(word);
                    word="";
                }
            }
            else{
                word+=s[i];
            }
        }
        if(word != ""){//It means that the word variable contains a word that is why it is not empty.
            st.push(word);
        }
        string ans="";
        
        int size=st.size();
        for(int i=0; i<size-1; i++){
            ans+=st.top() + " ";
            st.pop();
        }
        ans+=st.top();
        st.pop();
        return ans;
    }
};