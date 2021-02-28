class Solution {
public:

    bool match(int *map1, int *map2){
        // int n = *(&map1+1) - map1;
        for (int i=0; i< 26; i++){
            if (map1[i] != map2[i]) return false;
        }
        return true;
        
    }
    
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        int s1map[26] = {0};
        int s2map[26] = {0};
        // a = 97
        
        // For making the hashset of length of string s1 
        for (int i=0; i < s1.size(); i++){
            s1map[int(s1[i])-97]++;
            s2map[int(s2[i])-97]++;
        }
        
        // For sliding the window and check its equality
        for (int i = 0; i < s2.size()-s1.size(); i++){
            if (match(s1map, s2map)) return true;
            
            ++s2map[int(s2[i+s1.size()])-97];
            --s2map[int(s2[i])-97];
        }
        
        return match(s1map, s2map);

        
    }
};