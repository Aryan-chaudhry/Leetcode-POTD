class Solution {
public:

    vector<int> findNextSmaller(vector<int>&heights){
        vector<int>ans;
        stack<int>st;
        st.push(-1);

        for(int i=heights.size()-1; i>=0; i--){
            int element = heights[i];
            while(st.top() != -1 && heights[st.top()] >= element){
                st.pop();
            }
            ans.push_back(st.top());
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<int> findprevSmaller(vector<int>&heights){
        vector<int>ans;
        stack<int>st;
        st.push(-1);

        for(int i=0; i<heights.size(); i++){
            int element = heights[i];
            while(st.top() != -1 && heights[st.top()] >= element){
                st.pop();
            }
            ans.push_back(st.top());
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>prevSmaller;
        vector<int>nextSmaller;

        nextSmaller = findNextSmaller(heights);
        prevSmaller = findprevSmaller(heights);


        for(int i=0; i<nextSmaller.size(); i++){
            if(nextSmaller[i] == -1){
                nextSmaller[i] = nextSmaller.size();
            }
        }

        for(auto no : prevSmaller){
            cout << no << " ";
        }

        cout << endl;

        for(auto no : nextSmaller){
            cout << no << " ";
        }
        
        
        

        int maxArea = INT_MIN;

        for(int i=0; i<heights.size(); i++){
            int width = nextSmaller[i]-prevSmaller[i]-1;
            int height = heights[i];
            int area = width*height;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};