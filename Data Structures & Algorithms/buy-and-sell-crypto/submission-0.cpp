class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //always i want to buy for cheap and sell at high price
        int ans=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            int diff=0;
            for(int j=i+1;j<n;j++){
                diff=prices[j]-prices[i];
                ans=max(ans,diff);
            }
            
        }
        return ans;
    }
};
