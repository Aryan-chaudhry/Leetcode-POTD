class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>leftGreater(height.size());
        vector<int>rightGreater(height.size());
        int waterTrapped = 0;

        leftGreater[0] = height[0];

        for(int i=1; i<height.size(); i++){
            leftGreater[i] = max(leftGreater[i-1],height[i]);
        }

        rightGreater[rightGreater.size()-1] = height[height.size()-1];

        for(int i=height.size()-2; i>=0; i--){
            rightGreater[i] = max(rightGreater[i+1], height[i]);
        }

        for(int i=0; i<height.size(); i++){
            if(height[i] < leftGreater[i] && height[i] < rightGreater[i]){
                waterTrapped += (min(leftGreater[i], rightGreater[i])-height[i]);
            }
        }
        return waterTrapped;
    }
};