class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
     
        //The below approach is giving TLE Error.
        
//         int sum = 0;
//         int min_num;
//         int length = arr.size();
//         int temp = 0;
        
//         for(int sp=0; sp<length; sp++){
            
//             for(int ep=sp; ep<length; ep++){
                
//                 min_num = INT_MAX;
//                 for(int i=sp; i<=ep; i++){
                    
//                     if(sp == ep){
//                         sum+=arr[i];
//                         temp = 1;
//                     }
//                     else{
//                         if(arr[i] < min_num){
//                             min_num = arr[i];
//                             temp = 0;
//                         }
//                     }
//                 }
//                 if(temp == 0){
//                     sum+=min_num;
//                 }
//             }
//         }
//         return sum;
        
        
        
        //copied
        int n = arr.size();
        vector<pair<int,int>> order(n);
        long long ans = 0;
        const long long mod = 1e9 + 7;

        for(int i = 0; i < n; i++)
            order[i] = {arr[i], i};

        sort(order.begin(), order.end());

        function<void(int, int, int)> helper = [&](int low, int high, int pos) {
            int nextp = order[pos].second;

            while(nextp < low or nextp > high){
                nextp = order[++pos].second;
            }

            long long left = nextp - low + 1;
            long long right = high - nextp + 1;

            ans = (ans + (left * right * arr[nextp]) % mod) % mod;

            if(nextp > low)
                helper(low, nextp - 1, pos + 1);
            if(nextp < high)
                helper(nextp + 1, high, pos + 1);
        };

        helper(0, n - 1, 0);

        return ans;
    }
};