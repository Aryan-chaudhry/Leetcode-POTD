class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>output;

        for(int i=0; i<intervals.size(); i++){
            if(output.empty()){
                output.push_back(intervals[i]);
            }
            else{
                vector<int>&track = output.back();
                int previous = track[1];

                int curr = intervals[i][0];

                if(curr <= previous){
                    
                    track[1] = max(previous, intervals[i][1]);
                }
                else{
                    output.push_back(intervals[i]);
                }
            }
        }
        return output;
    }
};