class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>>nums;//stores position ,speed
        for(int i=0;i<n;i++){
            nums.push_back({position[i],speed[i]});
        }
        sort(nums.rbegin(),nums.rend());//sort from heigh to low in respect to the position
        int count=0;
        double lastTime=0;
        for(int i=0;i<n;i++){
            double time = (double)(target - nums[i].first) / nums[i].second;
            if(lastTime<time){
                count++;
                lastTime=time;
            }
        }
        return count;
    }
};
