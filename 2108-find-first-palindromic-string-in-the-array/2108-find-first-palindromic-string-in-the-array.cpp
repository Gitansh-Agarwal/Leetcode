class Solution {
public:
    int isPalindrome(string reverseWord){
        // string word = reverseWord;
        // reverse(reverseWord.begin(), reverseWord.end());
        // if(word == reverseWord)
        //     return 1;
        // return 0;
        
        // OR
        
        bool ok = 1;
        int n = reverseWord.size(); 
        for(int i=0; i<n/2; i++){
            if(reverseWord[i] != reverseWord[n-i-1]){
                ok = 0;
                break;
            }
        }
        if(ok)
            return 1;
        return 0;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto it: words){
            if(isPalindrome(it))
                return it;
        }
        return "";
    }
};