#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        vector<int>lh(n,0),rh(n,0);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty()==true)lh[i]=0;
            else 
            {
                lh[i]=st.top()+1;
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and heights[st.top()]>=heights[i])st.pop();
            if(st.empty())rh[i]=n-1;
            else rh[i]=st.top()-1;
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,(rh[i]-lh[i]+1)*heights[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int ans=0;
        vector<int>heights(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]-'0'==1)
                {
                    heights[j]++;
                }
                else heights[j]=0;
            }
            
            ans=max(ans,largestRectangleArea(heights));
        }
        return ans;
    }
};
int main(){
    Solution s;
    
return 0;
}