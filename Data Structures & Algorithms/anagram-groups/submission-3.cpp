class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mpp;
        for(int i=0;i<strs.size();i++){
        int freq[26]={0};
            for(int j=0;j<strs[i].size();j++){
                freq[strs[i][j]-'a']++;
            }
            string key="";
            for(int j=0;j<26;j++){
                key+=to_string(freq[j])+"#";
            }
            mpp[key].push_back(strs[i]);
        }
        for(auto &it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
