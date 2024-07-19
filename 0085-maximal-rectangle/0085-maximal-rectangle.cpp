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
    int largestRectangleArea(vector<int> heights) {
        vector<int> left=pse(heights);
        vector<int> right=nse(heights);

        int maxarea=-1;
        int n=heights.size();
        for(int i=0;i<n;i++){
            maxarea=max(maxarea,heights[i]*(right[i]-left[i]-1));
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(i==0){
                    if(matrix[i][j]=='1'){
                        dp[i][j]=1;
                    }else{
                        dp[i][j]=0;
                    }
                }
                else{
                    if(matrix[i][j]=='0'){
                        continue;
                    }else{
                        dp[i][j]=dp[i-1][j]+1;
                    }
                }
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        int maxi=-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,largestRectangleArea(dp[i]));
        }
        return maxi;
    }
};