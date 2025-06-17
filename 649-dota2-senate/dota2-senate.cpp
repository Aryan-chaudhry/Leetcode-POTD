class Solution {
public:
    string predictPartyVictory(string senate) {
       queue<int>radiantQ, direQ;
       int position = 0;

        for(;position<senate.size(); position++){
            char senator = senate[position];
            if(senator == 'R') radiantQ.push(position);
            if(senator == 'D') direQ.push(position);
        }

        while(!radiantQ.empty() && !direQ.empty()){
            int rFront = radiantQ.front();
            radiantQ.pop();

            int dFront = direQ.front();
            direQ.pop();

            // simulation voting
            if(rFront < dFront){
                // means r will ban d
                radiantQ.push(position++);
            }
            else{
                // means d will ban r
                direQ.push(position++);
            }
        }

        if(!radiantQ.empty()) return "Radiant";
        return "Dire";
    }
};