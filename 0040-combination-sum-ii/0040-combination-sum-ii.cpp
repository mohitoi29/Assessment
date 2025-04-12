class Solution {
private:
    void func(int index,int target,vector<int>& subAns,vector<vector<int>>& sol, vector<int>& arr){
      
            if(target==0){
                sol.push_back(subAns);
                return;
            }
            
        for(int i=index;i<arr.size();i++){
            if(i>index && arr[i]==arr[i-1])
            continue;
            if(arr[i]>target)
            break;
            subAns.push_back(arr[i]);
            func(i+1,target-arr[i],subAns,sol,arr);
            subAns.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> subAns;
        vector<vector<int>> sol;
        func(0,target,subAns,sol,candidates);
        return sol;
    }
};