class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;//this stores my number and the index where i found it 
        // mpp[0]=0;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(target-nums[i])==mpp.end()){
                mpp[nums[i]]=i;
            }else{
                return {mpp[target-nums[i]],i};
            }
        }
        return {-1,-1};
    }
};
