class Solution {
private:
 void func(int index,vector<vector<int>>& sol,vector<int>& subsum,vector<int>& candidate,int target){
    if(index==candidate.size()){
        if(target==0)
        sol.push_back(subsum);
        return;
    }
    if(candidate[index]<=target){
        subsum.push_back(candidate[index]);
        func(index,sol,subsum,candidate,target-candidate[index]);
        subsum.pop_back();
    }
    func(index+1,sol,subsum,candidate,target);

 }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> sol;
        vector<int> subsum;
        func(0,sol,subsum,candidates,target);
        return sol;
    }
};