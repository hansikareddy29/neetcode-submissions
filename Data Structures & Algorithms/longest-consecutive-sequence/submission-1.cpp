class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
       unordered_set<int>st(nums.begin(),nums.end());
        int maxi=0;
       for(int num:nums){
        if(st.find(num-1)==st.end()){
            int curr=num;
            int count=1;
            while(st.find(curr+1)!=st.end()){
                curr++;
                count++;
            }
            maxi=max(maxi,count);
        }
       }
        return maxi;
    }
};
