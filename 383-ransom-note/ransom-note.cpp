class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       unordered_map<char,int>mp;

       for(auto ch : magazine){
            mp[ch]++;
       }

       for(int i=0; i<ransomNote.length(); i++){
            char ch = ransomNote[i];
            if(mp.find(ch) == mp.end()){
                return false;
            }
            else{
                if(mp[ch] <= 0){
                    return false;
                }
                else{
                    mp[ch]--;
                }
            }
       }
    return true;        
    }
};