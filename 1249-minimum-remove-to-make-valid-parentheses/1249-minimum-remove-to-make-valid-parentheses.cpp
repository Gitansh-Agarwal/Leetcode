class Solution {
public:
    string minRemoveToMakeValid(string s) {
        //
        string res="";
        int cnt=0;
        int n=s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                res+='(';
                cnt+=1;
            }
            else if(s[i]==')' and cnt>0){
                res+=')';
                cnt-=1;
            }
            else if(s[i]!=')'){
                res+=s[i];
            }
        }
        
        
        //filtering on the extra open brackets in the string
        string filtered="";
        for(int i=res.size()-1; i>=0; i--){
            if(res[i]=='(' and cnt>0){
                cnt--;
            }
            else{
                filtered+=res[i];
            }
        }
        //as the string res is actually copied in reverse order, so we have to again reverse the filtered string to get it in the correct order.
        reverse(filtered.begin(), filtered.end());
        
        return filtered;
    }
};