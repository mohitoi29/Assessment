class Solution {
private:
 void func(  vector<vector<int>>& sol,vector<int>& subAns,vector<int>& nums, vector<bool>& check){
    if(subAns.size()==nums.size()){
        sol.push_back(subAns);
        return ;
    }
    for(int i=0;i<nums.size();i++){
    if(!check[i]){
        subAns.push_back(nums[i]);
        check[i]=true;
        func(sol,subAns,nums,check);
        check[i]=false;
        subAns.pop_back();
    }
    }
 }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> subAns;
        vector<bool> check(nums.size(),false);
        func(sol,subAns,nums,check);
        return sol;
    }
};