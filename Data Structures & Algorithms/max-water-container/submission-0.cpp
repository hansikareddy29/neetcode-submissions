class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int low=0;
        int high=n-1;
        int maxi=0;
        while(low<high){
            int width=high-low;
            int height=min(heights[low],heights[high]);
            maxi=max(maxi,width*height);
            //we got the current container but sinsce we want maximize our answer 
            //we will try out all possible amswers
            if(heights[low]<heights[high]) low++;
            else high--;//the lowest is the bottle neck here 
            //if somehow we will remove taht lowest and try for a better or much higher bar we can get maxi
        }
            return maxi;
    }
};
