class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>store(256, 0);

        for(int i=0; i<s.size(); i++){
            store[int(s[i])]++;       
        }

        for(int i=0; i<t.size(); i++){
            store[int(t[i])]--;
        }

        for(int i=0; i<store.size(); i++){
            if(store[i] != 0){
                return false;
            }
        }
        
        return true;
    }
};