class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.size() != t.size()) return false;
        
        unordered_map<char, int> map;
        
        
        int i = 0;
        while(i < s.size()){
            map[int(s[i])-97]++;
            map[int(t[i++])-97]--;
        }
        
        for(auto c: map){
            if (c.second) return false;
        }
        
        return true;
    }
};