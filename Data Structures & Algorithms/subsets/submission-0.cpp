class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>subset;
        dfs(nums,0,subset,ans);
        return ans;
    }
    void dfs(vector<int> &nums,int ind,vector<int> &subset,vector<vector<int>> &ans){
        if(ind==nums.size()){
            ans.push_back(subset);
            return;
        }
        //take nums[ind] into our answer
        subset.push_back(nums[ind]);
        dfs(nums,ind+1,subset,ans);
        //don't take nums[ind] into our answer
        subset.pop_back();
        dfs(nums,ind+1,subset,ans);
    }
};
