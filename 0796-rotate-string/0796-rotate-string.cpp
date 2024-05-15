class Solution {
public:
    bool rotateString(string s, string goal) {
        // int index=-1;
        // //Finding out the position of the first character of string s in string goal.
        // for(int i=0; i<)
        
        int lengthOfS=s.length();
        for(int i=0; i<lengthOfS; i++){
            char temp=s[0];
            s.erase(0,1);
            s+=temp;
            
            if(s==goal){
                return true;
            }
        }
        return false;
    }
};