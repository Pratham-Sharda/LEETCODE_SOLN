class Solution {
public:
    vector<int> nse(vector<int>& heights){
        vector<int> ans(heights.size(),-1);
        stack<int> st;
        int n=heights.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
                ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> pse(vector<int> & heights){
        vector<int> ans(heights.size(),-1);
        stack<int> st;
        int n=heights.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
                ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left=pse(heights);
        vector<int> right=nse(heights);

        int maxarea=-1;
        int n=heights.size();
        for(int i=0;i<n;i++){
            maxarea=max(maxarea,heights[i]*(right[i]-left[i]-1));
        }
        return maxarea;
    }
};