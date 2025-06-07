class Solution {
public:
    int maxArea(vector<int>& height) {
        int st = 0l;
        int end = height.size()-1;

        int maxArea = 0;

        while(st < end){
            int area = min(height[st],height[end])*(end-st);
            maxArea = max(maxArea, area);
            
            if(height[st] < height[end]){
                st++;
            }
            else{
                end--;
            }
        }
        return maxArea;
    }
};