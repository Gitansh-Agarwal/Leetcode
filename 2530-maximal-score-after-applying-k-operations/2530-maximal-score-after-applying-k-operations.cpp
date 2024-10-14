class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long int score=0;
        int n=nums.size();
        // priority_queue<int> pq(std::less<int>(), nums);
        //OR priority_queue<int> pq(nums.begin(), nums.end());
        priority_queue<int> pq(begin(nums), end(nums));
        // while(!pq.empty()){
        //     cout<<pq.top()<<endl;
        //     pq.pop();
        // }
        for(int i=0; i<k; i++){
            int originalVal = pq.top();
            int reqVal = (ceil)(originalVal/3.0);
            pq.pop();
            // cout<<val<<endl;
            pq.push(reqVal);
            score+= originalVal;
        }
        return score;
    }
};