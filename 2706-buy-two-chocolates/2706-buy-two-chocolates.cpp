class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        
        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;
        int length = prices.size();
        int leftoverMoney;
        for(int i=0; i<length; i++){
            if(prices[i] < smallest){
                secondSmallest = smallest;
                smallest = prices[i];
            }
            else if(prices[i] < secondSmallest){
                secondSmallest = prices[i];
            }
        }
        leftoverMoney = money - (smallest + secondSmallest);
        if(leftoverMoney >= 0){
            return leftoverMoney;
        }
        return money;
    }
};