class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
        //Sorting the given 2d vector points on the basis of 1st column of every row in ascending order(by default) or according to this question we are just sorting the entire 2d array points based on the x- coordinate of the different points.
        
        
        // sort(points.begin(),points.end(), [](const vector<int>& a, const vector<int>& b){
        //     return a[0] < b[0];
        // });
        
        // OR
        
        sort(points.begin(),points.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
        
        int maximumWidth = 0;
        for(int i=1; i<points.size(); i++){
            maximumWidth = max(maximumWidth, points[i][0]-points[i-1][0]);
        }
        return maximumWidth;
    }
};