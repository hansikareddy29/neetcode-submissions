class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>buckets(n+1);
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto &it:mpp){
            int num=it.first;
            int freq=it.second;
            buckets[freq].push_back(num);
        }
        vector<int>ans;
        for(int i=buckets.size()-1;i>=0;i--){
            for(int j=0;j<buckets[i].size();j++){
                ans.push_back(buckets[i][j]);
                if(ans.size()==k) return ans;
            }
        }
        return ans;
    }
};
