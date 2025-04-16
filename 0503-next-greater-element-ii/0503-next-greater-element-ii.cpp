class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>nge(nums.size());
        stack<int> s;
        for(int i=2*nums.size()-1;i>=0;i--){
            while(!s.empty()&& s.top()<=nums[i%nums.size()]){
                s.pop();
            }
            if(i<nums.size())
            nge[i]=s.empty()?-1:s.top();
            s.push(nums[i%nums.size()]);
        }
        return nge;
    }
};