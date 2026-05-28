class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>subset;
        dfs(target,nums,0,subset,ans);
        return ans;
    }
    void dfs(int target,vector<int> &nums,int ind,vector<int> &subset,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(subset);
            return;
        }
        if(target<0 || ind>=nums.size()){
            return;
        }
            subset.push_back(nums[ind]);
            dfs(target-nums[ind],nums,ind,subset,ans);//check on the same index again
            subset.pop_back();
            dfs(target,nums,ind+1,subset,ans);
        
    }
};
