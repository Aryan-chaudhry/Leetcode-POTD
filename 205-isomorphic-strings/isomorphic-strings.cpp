class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp;
        unordered_set<char>st;

        for(int i=0; i<s.length(); i++){
            if(mp.find(s[i]) == mp.end()){
                // nahi hai

                // hum ek case bhulte hai ki hum s to k se map to karwa rahe hai
                // par bhul ja rahe haiki t char agar map ho gaya hai to kisi or ke sath map nahi ho sakta
                
                if(st.find(t[i]) == st.end()){
                    // t char kisi ke sath map nahi hai
                    mp[s[i]] = t[i]; // map kar deya
                    st.insert(t[i]); // map ho gaya hai to track rakho
                }
                else{
                    // t char pehele se hi kisi ke sath map hai
                    // vapis map nahi kar sakte
                    return false;
                }

            }
            else{
                // hai
                if(mp[s[i]] != t[i]){
                    return false;
                }
            }
        }
        return true;
    }
};