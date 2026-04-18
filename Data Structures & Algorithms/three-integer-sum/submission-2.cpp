class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
       for(int low=0;low<n;low++){
            if(low>0 && nums[low]==nums[low-1]) continue;
            int mid=low+1;
            int high=n-1;
            while(mid<high){
            int sum=nums[low]+nums[mid]+nums[high];
            if(sum==0){
                ans.push_back({nums[low],nums[mid],nums[high]});
                mid++;
                high--;
                while(mid<high && nums[mid]==nums[mid-1]) mid++;
                while(mid<high && nums[high]==nums[high+1]) high--;
            }
            else if(sum>0) high--;
            else mid++;
            }
        }
        return ans;
    }
};
