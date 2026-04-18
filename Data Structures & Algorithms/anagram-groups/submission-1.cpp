class Solution {
public:
    bool isAnagram(string &s,string &t){
        if(s.size()!=t.size()) return false;
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
            mpp[t[i]]--;
        }
        for(auto &it:mpp){
            if(it.second!=0) return false;
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>>ans;
        vector<bool>done(n,false);
        for(int i=0;i<n;i++){
            vector<string>arr;
            if(!done[i]){
            arr.push_back(strs[i]);
            done[i]=true;//true
            for(int j=i+1;j<n;j++){
                if(done[j]==false && isAnagram(strs[i],strs[j])){
                    arr.push_back(strs[j]);
                    done[j]=true;
                }
            }
            ans.push_back(arr);
            }
        }
        return ans;
    }
};
