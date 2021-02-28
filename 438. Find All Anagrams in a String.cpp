class Solution {
public:
    
    bool match(int *map1, int *map2){
        for(int i=0; i<26; i++)
            if (map1[i] != map2[i]) return false;
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        
        if (p.size() > s.size()) return ans;
        
        int smap[26] = {0};
        int pmap[26] = {0};
        
        for(int i=0; i<p.size(); i++){
            ++smap[int(s[i])-97];
            ++pmap[int(p[i])-97];
        }
        
        for(int i=0; i<s.size()-p.size(); i++){
            if(match(smap, pmap)) ans.push_back(i);
            
            --smap[int(s[i])-97];
            ++smap[int(s[i+p.size()])-97];
        }
        
        if (match(smap, pmap)) ans.push_back(s.size()-p.size());
        
        return ans;
    }
};