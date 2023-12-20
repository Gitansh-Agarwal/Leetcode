class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        
        // Below solution takes O(N) time.
        // Intuition is to find the minimum and the second minimum element in the array and sum them as their sum will be minimum.
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
        
        //Below method uses sorting the two arrays and it takes O(Nlog(N)) time.
        // sort(prices.begin(),prices.end());
        // int leftoverMoney = money - (prices[0] + prices[1]);
        // if(leftoverMoney >= 0)
        //     return leftoverMoney;
        // return money;
    }
};