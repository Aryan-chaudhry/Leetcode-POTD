class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0;
        int point = 0;

        // maintian initail ans
        maxAltitude = max(maxAltitude, point);

        for(int i=0; i<gain.size(); i++){
            point += gain[i];
            maxAltitude = max(maxAltitude, point);
        }
        return maxAltitude;
    }
};