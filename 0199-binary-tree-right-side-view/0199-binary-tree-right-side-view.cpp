/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    // int height(TreeNode* root){
    //     if(root==nullptr) return 0;
    //     int leftside=height(root->left);
    //     int rightside=height(root->right);
    //    return max(leftside,rightside)+1;
    // }
    void func(TreeNode* root,vector<int>& sol,int level){
            if(root==nullptr)return;
            if(level==sol.size())sol.push_back(root->val);
            func(root->right,sol,level+1);
            func(root->left,sol,level+1);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> sol;
        func(root,sol,0);
        return sol;
    }
};