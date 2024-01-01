class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int lengthS = s.size();
        if(lengthS==0)
            return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int lengthG = g.size();
        int i=0, j=0; 
        while(i<lengthG && j<lengthS){
            if(g[i] <= s[j]){
                count++;
                i++;
                j++;
            }
            else if(g[i] > s[j])
                j++;
                
        }
        return count;
    }
};