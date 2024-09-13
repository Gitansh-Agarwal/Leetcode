class Solution {
public:
    struct hash_pair {
        template <class T1, class T2>
        size_t operator()(const std::pair<T1, T2>& p) const {
            auto hash1 = std::hash<T1>{}(p.first);
            auto hash2 = std::hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };

    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
//         unordered_map<pair<int, int>, int, hash_pair> myMap;
//         int n1 = arr.size();
//         for(int i=0; i<n1; i++){
//             int xorVal = 0;
//             for(int j=i; j<n1; j++){
//                 xorVal = xorVal ^ arr[j];
//                 myMap[{i, j}] = xorVal;
//             }
//         }
        
//         int n2 = queries.size();
//         vector<int> ans(n2, 0);

//         for(int i=0; i<n2; i++){
//             ans[i] = myMap[{queries[i][0], queries[i][1]}];
//         }
//         return ans;
        
        int n1 = arr.size();
        int n2 = queries.size();
        
        vector<int> ans(n2, 0);
        
        for(int i=0; i<n2; i++){
            int xorVal = 0;
            for(int j=queries[i][0]; j<=queries[i][1]; j++){
                xorVal^=arr[j];
            }
            ans[i] = xorVal;
        }
        return ans;
    }
};