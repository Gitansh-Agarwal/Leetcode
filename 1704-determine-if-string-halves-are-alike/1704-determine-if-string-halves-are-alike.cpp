class Solution {
public:
    bool halvesAreAlike(string s) {
        vector<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        int count1=0;
        int count2=0;
        for(int i=0; i<s.size(); i++){
            if(i<s.size()/2 && find(vowels.begin(),vowels.end(),s[i])!=vowels.end())
                count1++;
            else {
                if(find(vowels.begin(),vowels.end(),s[i])!=vowels.end())
                    count2++;
            }
        }
        return count1==count2;
    }
};