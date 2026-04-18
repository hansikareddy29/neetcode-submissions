class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int>spp;
        for(int i=0;i<s.size();i++){
            spp[s[i]]++;
            spp[t[i]]--;
        }
        for(auto &it:spp){
           if(it.second!=0) return false;
        }
        return true;
    }
};
