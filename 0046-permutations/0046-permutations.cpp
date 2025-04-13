class Solution {
private:
    void perm(vector<int>& nums, vector<vector<int>> &ans,int index){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            perm(nums,ans ,index+1);
            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        perm(nums,ans,index);
        return ans;
    }
};