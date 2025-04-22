class Solution {
    vector<int> nse(vector<int>& nums){
            vector<int> ans(nums.size());
            stack<int> s;
            for(int i=nums.size()-1;i>=0;i--){
                    while(!s.empty() && nums[s.top()]>nums[i])
                        s.pop();
                    ans[i]=s.empty()? nums.size(): s.top();
                    s.push(i);
            }
           return ans; 
    }
    vector<int> pse(vector<int>& nums){
            vector<int> ans(nums.size());
            stack<int> s;
            for(int i=0;i<nums.size();i++){
                    while(!s.empty() && nums[s.top()]>=nums[i])
                        s.pop();
                    ans[i]=s.empty()?-1:s.top();
                    s.push(i);
            }
           return ans; 
}
    
    vector<int> nge(vector<int>& nums){
            vector<int> ans(nums.size());
            stack<int> s;
            for(int i=nums.size()-1;i>=0;i--){
                    while(!s.empty() && nums[s.top()]<nums[i])
                        s.pop();
                    ans[i]=s.empty()?nums.size():s.top();
                    s.push(i);
            }
           return ans; 
}

    vector<int> pge(vector<int>& nums){
            vector<int> ans(nums.size());
            stack<int> s;
            for(int i=0;i<nums.size();i++){
                    while(!s.empty() && nums[s.top()]<=nums[i])
                        s.pop();
                    ans[i]=s.empty()?-1:s.top();
                    s.push(i);
            }
           return ans; 
}
public:
    long long subArrayRanges(vector<int>& nums) {
        vector<int> ps=pse(nums);
         vector<int> ns=nse(nums);
         vector<int> pg=pge(nums);
         vector<int> ng=nge(nums);
         
         long long gtotal=0;
         long long stotal=0;
        for(int i=0;i<nums.size();i++){
            long long leftMin = i - ps[i];
            long long rightMin = ns[i] - i;
            stotal += leftMin * rightMin * nums[i];

            long long leftMax = i - pg[i];
            long long rightMax = ng[i] - i;
            gtotal += leftMax * rightMax * nums[i];       
    }
  
return gtotal-stotal;
    }
};