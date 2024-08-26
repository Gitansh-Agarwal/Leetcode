class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        int n=s.length();
        string word="";
        for(int i=0; i<n; i++){
            if(s[i]==' '){
                if(word==""){
                    continue;
                }
                else{
                    stk.push(word);
                    word="";
                }
            }
            else{
                word+=s[i];
            }
        }

        if(word!=""){
            stk.push(word);
        }
        string ans="";
        while(!stk.empty()){
            ans+=stk.top()+" ";
            stk.pop();
        }
        return ans.substr(0, ans.length()-1);
    }
};