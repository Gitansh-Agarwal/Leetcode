class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int i=0, j=n-1;
        while(i<j && s[i] == s[j]){
            ++i;
            while(i<j && s[i] == s[i-1])
                ++i;
            --j;
            while(i<j && s[j] == s[j+1])
                --j;
        }
        return j-i+1;
    }
};