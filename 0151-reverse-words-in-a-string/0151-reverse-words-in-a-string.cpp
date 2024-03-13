class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int length=s.size();
        string ans="";
        for(int i=0; i<length; i++){
            
            if(s[i] == ' '){
                if(ans==""){
                    continue;
                }
                else{
                    st.push(ans);
                    ans="";
                }
                    
                
            }
            else{
                ans+=s[i];
            }
        }
        if(ans != ""){
            st.push(ans);
        }
        ans="";
        // while(!st.empty()){
        //     ans+=st.top()+ " ";
        //     st.pop();
        // }
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