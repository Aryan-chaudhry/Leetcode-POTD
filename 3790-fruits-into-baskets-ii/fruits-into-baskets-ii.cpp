class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<int>track(fruits.size(), false);


        for(int i=0; i<fruits.size(); i++){
            int only1 = false;
            for(int j=0; j<baskets.size(); j++){
                if(baskets[j] >= fruits[i] && track[j] == false && only1 == false){
                    track[j] = true;
                    only1 = true;
                }
            }
        }

        for(auto no : track){
            cout << no << " ";
        }
        
        int noOfFruit = 0;
        for(int i=0; i<track.size(); i++){
            if(track[i] == false){
                noOfFruit++;
            }
        }
        return noOfFruit;
    }
};