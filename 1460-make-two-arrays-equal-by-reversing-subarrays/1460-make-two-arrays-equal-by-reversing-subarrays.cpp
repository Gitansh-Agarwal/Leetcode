class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> st1;
        unordered_map<int,int> st2;
        int n=target.size();
        for(int i=0; i<n; i++){
            st1[target[i]]++;
            st2[arr[i]]++;
        }
        if(st1==st2){
            return true;
        }
        return false;
    }
};