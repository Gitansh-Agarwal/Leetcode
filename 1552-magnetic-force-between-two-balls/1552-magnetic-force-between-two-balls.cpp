class Solution {
public:
    bool isPossible(vector<int>&position, int dist, int cows){
        int noOfCows=1;
        int lastCow=position[0];

        for(int i=1; i<position.size(); i++){
            if((position[i] - lastCow) >= dist){
                noOfCows++;
                lastCow=position[i];
            }
            if(noOfCows >= cows)
                return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
		int low=1;
        int N=position.size();
		int high=position[N-1]-position[0];
		int ans=-1;
		
		while(low<=high){
			int mid=(low+high)/2;
			
			if(isPossible(position, mid, m)==true){
				ans=mid;
				low=mid+1;
			}
			else{
				high=mid-1;
			}
		
		}
        return high;
		// cout<< high<<endl;
		//  or return ans;
    }
};