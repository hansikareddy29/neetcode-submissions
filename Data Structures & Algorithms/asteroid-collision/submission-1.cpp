class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            bool destroyed=false;
           while(!st.empty() && st.top()>0 && asteroids[i]<0){
            if(st.top()>abs(asteroids[i])){
                destroyed=true;
                break;
            }else if(st.top()<abs(asteroids[i])){
                st.pop();
            }else{
                destroyed=true;
                st.pop();
                break;
            }
           }
            if(!destroyed) st.push(asteroids[i]);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
//cases 
/*
nums=[3,2,1,8,7,9]
nums=[7,-8,-9,3]
nums[-8,-9,3] 
*/