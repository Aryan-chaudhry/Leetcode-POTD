class Solution {
public:
    char kthCharacter(int k) {
        string org = "a";

        while(org.size() < k){
            string copy = org;
            
            for(int i=0; i<copy.size(); i++){
                if(copy[i] != 'z'){
                    copy[i] = copy[i] + 1;
                }
                else{
                    copy[i] = 'a';
                }
            }

            org = org+copy;
        }
        return org[k-1];
    }
};