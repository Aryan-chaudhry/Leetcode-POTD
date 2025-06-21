class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickTimeG = 0;
        int travelTimeG = 0;
        int lastHouseG = 0;

        int pickTimeP = 0;
        int travelTimeP = 0;
        int lastHouseP = 0;

        int pickTimeM = 0;
        int travelTimeM = 0;
        int lastHouseM = 0;

        for(int i=0; i<garbage.size(); i++){
            string str = garbage[i];
            int index = 0;

            while(index < str.length()){
                if(str[index] == 'G'){
                    pickTimeG++;
                    lastHouseG = i;
                }
                else if(str[index] == 'P'){
                    pickTimeP++;
                    lastHouseP = i;
                }
                else{
                    pickTimeM++;
                    lastHouseM = i;
                }
                index++;
            }
        }

        for(int i=0; i<lastHouseG && i < travel.size(); i++){
            travelTimeG += travel[i];
        }

        for(int i=0; i<lastHouseP && i < travel.size(); i++){
            travelTimeP += travel[i];
        }

        for(int i=0; i<lastHouseM && i < travel.size(); i++){
            travelTimeM += travel[i];
        }

        int minTimeG = travelTimeG + pickTimeG;
        int minTimeP = travelTimeP + pickTimeP;
        int minTimeM = travelTimeM + pickTimeM;

        int totalMinTime = minTimeG + minTimeP + minTimeM;
        return totalMinTime;
    }
};