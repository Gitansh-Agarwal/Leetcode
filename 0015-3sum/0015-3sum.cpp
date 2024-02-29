class Solution {
public:
    struct hashFunction {
        size_t operator()(const vector<int>& myVector) const {
            std::hash<int> hasher;
            size_t answer = 0;
            for (int i : myVector) {
                answer ^= hasher(i);
            }
            return answer;
        }
    };
    vector<vector<int>> threeSum(vector<int>& nums) {
    // Write your code here.
    //TC=O(N^3 * log(no. of unique triplets))
    // int n=nums.size();
    // set<vector<int>> st;
    // for(int i=0; i<n; i++){
    //     for(int j=i+1; j<n; j++){
    //         for(int k=j+1; k<n; k++){
    //             if(nums[i]+nums[j]+nums[k] == 0){
    //                 vector<int> temp = {nums[i], nums[j], nums[k]};
    //                 sort(temp.begin(), temp.end());
    //                 st.insert(temp);
    //             }
    //         }
    //     }
    // }
    // vector<vector<int>> ans(st.begin(), st.end());
    // return ans;



    //TC=O(N^2 * logM {M is size of set})
    //SC=O(N){hashset} + O(no. of uniques).
    // set<vector<int>> st;
    // or
    // std::unordered_set<std::vector<int>, hashFunction> st;
    // int n=nums.size();
    // for(int i=0; i<n; i++){
    //     set<int> hashset;
    //     for(int j=i+1; j<n; j++){
    //         int third = -(nums[i] + nums[j]);
    //         if(hashset.find(third) != hashset.end()){
    //             vector<int> temp = {nums[i], nums[j], third};
    //             sort(temp.begin(), temp.end());
    //             st.insert(temp);
    //         }
    //         hashset.insert(nums[j]);
    //     }
    // }
    // vector<vector<int>> ans(st.begin(), st.end());
    // return ans;



    //Optimal Solution
    //TC=O(NlogN) + O(N^2)
    //SC=O(no. of uniques)
    vector<vector<int>> ans;
    int n=nums.size();
    sort(nums.begin(), nums.end());
    for(int i=0; i<n; i++){
        if(i>0 && nums[i] == nums[i-1])
            continue;
        int j= i+1;
        int k= n-1;

        while(j<k){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0){
                j++;
            }
            else if(sum > 0){
                k--;
            }
            else{
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && nums[j] == nums[j-1])   j++;
                while(j<k && nums[k] == nums[k+1])   k--;
            }
        }
    }
    return ans;
    }
};