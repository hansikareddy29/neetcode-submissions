class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int>spp,tpp;
        for(int i=0;i<s.size();i++){
            spp[s[i]]++;
            tpp[t[i]]++;
        }
        for(auto &it:spp){
            if(spp[it.first]!=tpp[it.first]){
                return false;
            }
            
        }
        return true;
    }
};
