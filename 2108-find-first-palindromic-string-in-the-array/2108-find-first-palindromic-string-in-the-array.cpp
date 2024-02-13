class Solution {
public:
    int isPalindrome(string reverseWord){
        string word = reverseWord;
        reverse(reverseWord.begin(), reverseWord.end());
        if(word == reverseWord)
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