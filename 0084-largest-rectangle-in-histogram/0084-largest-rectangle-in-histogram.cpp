class Solution {
    vector<int> nse(vector<int>& heights){
        stack<int> s;
        int n=heights.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]> heights[i]){
                s.pop();
            }
            ans[i]=s.empty()?n:s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> pse(vector<int>& heights){
        stack<int> s;
        int n=heights.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            ans[i]=s.empty()?-1:s.top();
            s.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsi=nse(heights);
        vector<int> psi=pse(heights);
        int area=0;
        int currArea=0;
        for(int i=0;i<heights.size();i++){
            currArea=heights[i]*(nsi[i]-psi[i]-1);
            area=max(currArea,area);
        }
        return area;
    }
};