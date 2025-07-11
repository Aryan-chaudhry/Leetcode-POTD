class Solution {
public:
    bool isVowel(char &ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int maxVowels(string s, int k) {
        unordered_map<int,bool>mp; // -> track that particular index have vowel or not
        int maxNo = 0;
        int count = 0;

        // process the first window of size k
        for(int i=0; i<k; i++){
            if(isVowel(s[i])){
                mp[i] = true;
                count++;
            }
            else{
                mp[i] = false;
            }
        }

        // fetch the answer
        maxNo = max(maxNo,count);

        int i = 0;
        // process the remainig window
        for(int j=k; j<s.length(); j++){
            // aage wala add karna hai , peche wala delete karna hai
            // but vowel ka dhyan rakhna hai
            

            // aage wala add kar leye vowel ko dhyan me rakhe hue
            if(isVowel(s[j])){
                mp[j] = true;
                count++;
            }
            else{
                mp[j] = false;
            }
            
            // peche wala delete kar deya vowel ko dhyan me rakhe hue
            if(isVowel(s[i++])){
                mp[i] = false;
                count--;
            }

            // fetch ans
            maxNo = max(maxNo,count);
        }
        return maxNo;
    }
};