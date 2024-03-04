class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        
        int maxScore = 0;
        int i=0, j=n-1;
        int score=0;
        sort(begin(tokens), end(tokens));
        while(i<=j){
            if(power >= tokens[i]){
                power-=tokens[i];
                score++;
                i++;
                maxScore = max(maxScore, score);
            }
            else if(score >= 1){
                power+=tokens[j];
                score--;
                j--;
            }
            else{
                return maxScore;
            }
        }
        return maxScore;
    }
};