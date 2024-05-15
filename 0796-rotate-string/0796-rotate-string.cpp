class Solution {
public:
    bool rotateString(string s, string goal) {
        //Assuming that both the strings s and t are of equal length.
        
        //The below method is not working fine.
//         int index=-1;
//         sort(s.begin(),s.end());
//         int lengthOfS=s.length();
//         //Finding out the position of the first character of string s in string goal.
//         for(int i=0; i<lengthOfS; i++){
//             if(goal[i]==s[0]){
//                 index=i;
//                 break;
//             }
//         }
//         for(int i=1; i<lengthOfS; i++){
//             char temp=goal[(index+i)%lengthOfS];
            
//             if(s[i]!=temp){
//                 return false;
//             }
//         }
//         return true;
        
        
        
        
        //This Below Method is working fine.
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