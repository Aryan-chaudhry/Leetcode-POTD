class Solution {
public:
    void nextSmaller(vector<int>&heights, vector<int>&next){
        stack<int>st;
        st.push(-1);

        for(int i=heights.size()-1; i>=0; i--){
            int element = heights[i];
            while(st.top() != -1 && heights[st.top()] >= element){
                st.pop();
            }
            next.push_back(st.top());
            st.push(i);
        }
        reverse(next.begin(),next.end());
    }

    
    void prevSmaller(vector<int>&heights, vector<int>&prev){
        stack<int>st;
        st.push(-1);
        
        for(int i=0; i<heights.size(); i++){
            int element = heights[i];
            while(st.top() != -1 && heights[st.top()] >= element){
                st.pop();
            }
            prev.push_back(st.top());
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int>next,prev;

        nextSmaller(heights, next);
        prevSmaller(heights, prev);

        for(int i=0; i<next.size(); i++){
            if(next[i] == -1){
                next[i] = next.size();
            }
        }

        int maxArea = 0;
        for(int i=0; i<heights.size(); i++){
            int width = next[i]-prev[i]-1;
            int length = heights[i];
            int area = length*width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};