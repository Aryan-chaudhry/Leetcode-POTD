class Solution {
public:
    bool rotateString(string s, string goal) {
    
        for(int shift = 0; shift <= s.length(); shift++){
            string track = s;
            reverse(track.begin(), track.end());
            reverse(track.begin(), track.begin()+shift);
            reverse(track.begin()+shift, track.end());

            if(track == goal){
                return true;
            }
        }
        return false;
    }
};