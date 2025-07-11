class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        vector<int>Nofreq;

        for(auto no : arr)
            mp[no]++;

        for(auto &[no, freq] : mp){
            Nofreq.push_back(freq);
        }

        int i=0, j=1;
        bool isUnique = true;
        sort(Nofreq.begin(), Nofreq.end());
        
        while(j < Nofreq.size()){
            if(Nofreq[i] == Nofreq[j]){
                isUnique = false;
                break;
            }
            i=j;
            j++;
        }
        return isUnique;
    }
};