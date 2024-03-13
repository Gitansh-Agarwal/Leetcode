class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        int length=s.size();
        string ans="";
        for(int i=0; i<length; i++){
            if(s[i] == '('){
                if(st.size() > 0){
                    ans+=s[i];
                }
                st.push('(');
            }
            else{
                st.pop();
                if(st.size() > 0){
                    ans+=s[i];
                }
            }
        }
        return ans;
    }
};